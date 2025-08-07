--PREGUNTA 4.a------------------------------------------------------------------
CREATE OR REPLACE TRIGGER t_actualizar_estadistica
AFTER INSERT ON PARTIDO
FOR EACH ROW
DECLARE
    v_local SELECCION.NOMBRE%TYPE;
    v_visit SELECCION.NOMBRE%TYPE;
BEGIN
    SELECT NOMBRE INTO v_local
    FROM SELECCION
    WHERE IDSELEC=:NEW.IDLOCAL;
    
    SELECT NOMBRE INTO v_visit
    FROM SELECCION
    WHERE IDSELEC=:NEW.IDVISIT;
    
    IF (:NEW.GOLESLOCAL>:NEW.GOLESVISIT) THEN
        --Cuando gana el local
        UPDATE estadistica
        SET JUGADOS=JUGADOS+1,GANADOS=GANADOS+1,
            GOLESFAVOR=GOLESFAVOR+:NEW.GOLESLOCAL,
            GOLESCONTRA=GOLESCONTRA+:NEW.GOLESVISIT,
            PUNTOS=PUNTOS+3
        WHERE NOMBRE=v_local;
        
        IF SQL%ROWCOUNT=0 THEN
            INSERT INTO ESTADISTICA
            VALUES(v_local,1,1,0,0,:NEW.GOLESLOCAL,:NEW.GOLESVISIT,3);
        END IF;
        
        --Cuando pierde el visitante
        UPDATE estadistica
        SET JUGADOS=JUGADOS+1,PERDIDOS=PERDIDOS+1,
            GOLESFAVOR=GOLESFAVOR+:NEW.GOLESVISIT,
            GOLESCONTRA=GOLESCONTRA+:NEW.GOLESLOCAL
        WHERE NOMBRE=v_visit;
        
        IF SQL%ROWCOUNT=0 THEN
            INSERT INTO ESTADISTICA
            VALUES(v_visit,1,0,0,1,:NEW.GOLESVISIT,:NEW.GOLESLOCAL,0);
        END IF;
        
    ELSE
        IF (:NEW.GOLESLOCAL<:NEW.GOLESVISIT) THEN
            --Cuando gana el visitante
            UPDATE estadistica
            SET JUGADOS=JUGADOS+1,GANADOS=GANADOS+1,
                GOLESFAVOR=GOLESFAVOR+:NEW.GOLESVISIT,
                GOLESCONTRA=GOLESCONTRA+:NEW.GOLESLOCAL,
                PUNTOS=PUNTOS+3
            WHERE NOMBRE=v_visit;
            
            IF SQL%ROWCOUNT=0 THEN
                INSERT INTO ESTADISTICA
                VALUES(v_visit,1,1,0,0,:NEW.GOLESVISIT,:NEW.GOLESLOCAL,3);
            END IF;
            
            --Cuando pierde el local
            UPDATE estadistica
            SET JUGADOS=JUGADOS+1,PERDIDOS=PERDIDOS+1,
                GOLESFAVOR=GOLESFAVOR+:NEW.GOLESLOCAL,
                GOLESCONTRA=GOLESCONTRA+:NEW.GOLESVISIT
            WHERE NOMBRE=v_local;
            
            IF SQL%ROWCOUNT=0 THEN
                INSERT INTO ESTADISTICA
                VALUES(v_local,1,0,0,1,:NEW.GOLESLOCAL,:NEW.GOLESVISIT,0);
            END IF;
            
        ELSE
            --Cuando el visitante y el local empatan
            --Visitante
            UPDATE estadistica
            SET JUGADOS=JUGADOS+1,EMPATADOS=EMPATADOS+1,
                GOLESFAVOR=GOLESFAVOR+:NEW.GOLESVISIT,
                GOLESCONTRA=GOLESCONTRA+:NEW.GOLESLOCAL,
                PUNTOS=PUNTOS+1
            WHERE NOMBRE=v_visit;
            
            IF SQL%ROWCOUNT=0 THEN
                INSERT INTO ESTADISTICA
                VALUES(v_visit,1,0,1,0,:NEW.GOLESVISIT,:NEW.GOLESLOCAL,1);
            END IF;
            
            --Local
            UPDATE estadistica
            SET JUGADOS=JUGADOS+1,EMPATADOS=EMPATADOS+1,
                GOLESFAVOR=GOLESFAVOR+:NEW.GOLESLOCAL,
                GOLESCONTRA=GOLESCONTRA+:NEW.GOLESVISIT,
                PUNTOS=PUNTOS+1
            WHERE NOMBRE=v_local;
            
            IF SQL%ROWCOUNT=0 THEN
                INSERT INTO ESTADISTICA
                VALUES(v_local,1,0,1,0,:NEW.GOLESLOCAL,:NEW.GOLESVISIT,1);
            END IF;
            
        END IF;
    END IF;
    
END;


SELECT * FROM ESTADISTICA
ORDER BY puntos DESC;


--PREGUNTA 4.b------------------------------------------------------------------
CREATE OR REPLACE PROCEDURE pr_mostrar_partidos
(p_nom_seleccion VARCHAR2)
IS
    CURSOR c_partido
    IS
    SELECT *
    FROM PARTIDO;
    
    v_id_seleccion SELECCION.IDSELEC%TYPE;
    v_regPart c_partido%ROWTYPE;
    v_nom_local SELECCION.NOMBRE%TYPE;
    v_nom_visit SELECCION.NOMBRE%TYPE;
BEGIN
    SELECT IDSELEC INTO v_id_seleccion
    FROM SELECCION
    WHERE NOMBRE=p_nom_seleccion;
    
    DBMS_OUTPUT.PUT_LINE('Resultados de los partidos de la selección de ' ||
                          p_nom_seleccion);
    DBMS_OUTPUT.PUT_LINE(' ');
    OPEN c_partido;
    LOOP
        FETCH c_partido INTO v_regPart;
        EXIT WHEN c_partido%NOTFOUND;
        
        --Nombre del local
        SELECT NOMBRE INTO v_nom_local
        FROM SELECCION
        WHERE IDSELEC=v_regPart.IDLOCAL;
        
        --Nombre del visitante
        SELECT NOMBRE INTO v_nom_visit
        FROM SELECCION
        WHERE IDSELEC=v_regPart.IDVISIT;
        
        IF (v_id_seleccion=v_regPart.IDLOCAL OR v_id_seleccion=v_regPart.IDVISIT) THEN
            DBMS_OUTPUT.PUT_LINE('Fecha ' || v_regPart.NUMFECHA || ': ' ||
                                 v_nom_local || ' ' || v_regPart.GOLESLOCAL ||
                                 ' - ' ||
                                 v_nom_visit || ' ' || v_regPart.GOLESVISIT);
        END IF;
        
    END LOOP;
    CLOSE c_partido;
    
EXCEPTION
    WHEN NO_DATA_FOUND THEN
        DBMS_OUTPUT.PUT_LINE('Nombre de selección no válido');
END;


SET SERVEROUTPUT ON;


BEGIN
    pr_mostrar_partidos('PERU');
END;