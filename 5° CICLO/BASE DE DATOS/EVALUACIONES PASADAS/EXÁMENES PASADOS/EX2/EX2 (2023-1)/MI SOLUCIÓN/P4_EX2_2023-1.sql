--PREGUNTA 4.a------------------------------------------------------------------
CREATE OR REPLACE FUNCTION f_sueldo_promedio
           (p_nom_universidad VARCHAR2, p_anio NUMBER) 
          RETURN NUMBER
          IS
              v_id_universidad UNIVERSIDAD.IDUNIVERSIDAD%TYPE;
              v_sue_prom NUMBER;
              ANIO_INVALIDO exception;
          BEGIN
              SELECT IDUNIVERSIDAD INTO v_id_universidad
              FROM universidad
              WHERE nombre=p_nom_universidad;
              
              IF p_anio <= EXTRACT(year from SYSDATE) THEN
                SELECT AVG(P.SUELDO) INTO v_sue_prom
                FROM profesional P, titulacion T
                WHERE t.iduniversidad=v_id_universidad and 
                      t.idprofesional=p.idprofesional and 
                      EXTRACT(year from t.fecha)=p_anio;
              ELSE
                raise ANIO_INVALIDO;
              END IF;
              RETURN ROUND(v_sue_prom);
          EXCEPTION
              WHEN NO_DATA_FOUND THEN
                  RETURN -1;
              WHEN ANIO_INVALIDO THEN
                  RETURN -1;
          END;

SET SERVEROUTPUT ON;

DECLARE
    v_nom_universidad VARCHAR2(10);
    v_anio NUMBER;
    v_sue_prom NUMBER;
BEGIN
    v_nom_universidad := 'UNMSM';
    v_anio := 2023;
    v_sue_prom := f_sueldo_promedio(v_nom_universidad,v_anio);
    IF v_sue_prom = -1 THEN
        DBMS_OUTPUT.PUT_LINE('Universidad no existe y/o año no es válido');
    ELSE
        DBMS_OUTPUT.PUT_LINE('El sueldo promedio de los profesionales que se titularon en la ');
        DBMS_OUTPUT.PUT_LINE(v_nom_universidad || ' el año ' || v_anio || ' es ' || v_sue_prom);
    END IF;
END;


--PREGUNTA 4.b------------------------------------------------------------------
CREATE OR REPLACE PROCEDURE p_cant_titulados_ingenieros
       (p_sexo CHAR)
      IS
          CURSOR c_profesion
          IS
          SELECT * FROM profesion
          WHERE nombre LIKE 'Ingeniero%';
          
          CURSOR c_universidad
          IS
          SELECT * FROM universidad
          ORDER BY nombre DESC;
          
          v_cant_tit NUMBER;
          v_regProf c_profesion%ROWTYPE;
          v_regUniv c_universidad%ROWTYPE;
          SEXO_INVALIDO exception;
      BEGIN
          IF p_sexo='M' or p_sexo='F' THEN
            
            IF p_sexo='M' THEN
                DBMS_OUTPUT.PUT_LINE('Cantidad de ingenieros titulados de sexo Masculino');
            ELSE
                DBMS_OUTPUT.PUT_LINE('Cantidad de ingenieros titulados de sexo Femenino');
            END IF;
            DBMS_OUTPUT.PUT_LINE(' ');
            
            OPEN c_profesion;
            LOOP
                FETCH c_profesion INTO v_regProf;
                EXIT WHEN c_profesion%NOTFOUND;
                DBMS_OUTPUT.PUT_LINE(v_regProf.nombre);
                
                OPEN c_universidad;
                LOOP
                    FETCH c_universidad INTO v_regUniv;
                    EXIT WHEN c_universidad%NOTFOUND;
                    
                    SELECT COUNT(T.idprofesional) INTO v_cant_tit
                    FROM titulacion T,profesional P
                    WHERE p.sexo=p_sexo AND p.idprofesional=t.idprofesional AND
                          t.idprofesion=v_regProf.idprofesion AND
                          t.iduniversidad=v_regUniv.iduniversidad;
                    
                    IF v_cant_tit<>0 THEN
                        DBMS_OUTPUT.PUT_LINE('  ' || v_regUniv.nombre || ' - ' || v_cant_tit);
                    END IF;
                    
                END LOOP;
                CLOSE c_universidad;
                
                DBMS_OUTPUT.PUT_LINE(' ');
            END LOOP;
            CLOSE c_profesion;
          ELSE
            raise SEXO_INVALIDO;      
          END IF;
      EXCEPTION
          WHEN SEXO_INVALIDO THEN
            DBMS_OUTPUT.PUT_LINE('El sexo ingresado es inválido');
      END;
      

BEGIN
    p_cant_titulados_ingenieros('M');
END;


--PREGUNTA 4.c------------------------------------------------------------------
CREATE OR REPLACE TRIGGER t_insertar_titulados_pucp
AFTER INSERT ON TITULACION
FOR EACH ROW
DECLARE
    v_id_universidad UNIVERSIDAD.IDUNIVERSIDAD%TYPE;
    v_cant_tit NUMBER;
    v_profesion PROFESION.NOMBRE%TYPE;
BEGIN
    SELECT IDUNIVERSIDAD INTO v_id_universidad
    FROM universidad
    WHERE nombre LIKE 'PUCP%';
    
    IF (:NEW.IDUNIVERSIDAD=v_id_universidad) THEN
        SELECT p.nombre INTO v_profesion
        FROM PROFESION p
        WHERE p.IDPROFESION=:NEW.IDPROFESION;
        
        UPDATE TITULADOS_PUCP
        SET cantidad=cantidad+1
        WHERE profesion=v_profesion;
        
        if SQL%ROWCOUNT=0 THEN
            INSERT INTO TITULADOS_PUCP (PROFESION,CANTIDAD)
            VALUES (v_profesion,1);
        END IF;
        
    END IF;
END;


SELECT *
FROM TITULADOS_PUCP;