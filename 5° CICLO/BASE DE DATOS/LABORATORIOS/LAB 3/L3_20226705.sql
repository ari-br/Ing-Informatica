--PREGUNTA 1
CREATE OR REPLACE FUNCTION fn_total_buses_tipo
           (p_id_tipo_bus NUMBER) 
          RETURN NUMBER
          IS
              v_total_buses NUMBER;
              v_id_tipo_bus TIPO_BUS.ID_TIPO_BUS%TYPE;
          BEGIN
              SELECT ID_TIPO_BUS INTO v_id_tipo_bus
              FROM TIPO_BUS
              WHERE p_id_tipo_bus=TO_NUMBER(ID_TIPO_BUS);
              
              SELECT SUM(CANTIDAD)
              INTO v_total_buses
              FROM DETALLE_ORD_PEDIDO
              WHERE v_id_tipo_bus=ID_TIPO_BUS;
              RETURN NVL(v_total_buses,0);
          EXCEPTION
                WHEN NO_DATA_FOUND THEN
                    RETURN 0;
          END;

-- Caso 1:
SELECT fn_total_buses_tipo(1) FROM DUAL;

-- Caso 2:
SELECT fn_total_buses_tipo(5) FROM DUAL;

-- Caso 3:
SELECT fn_total_buses_tipo(999) FROM DUAL;


--PREGUNTA 2
CREATE OR REPLACE FUNCTION fn_eficiencia_entrega_sede
           (p_id_sede NUMBER) 
          RETURN NUMBER
          IS
              v_porc NUMBER;
              v_cantOrdTotal NUMBER;
              v_cantOrdEsp NUMBER;
              v_id_sede SEDE.ID_SEDE%TYPE;
          BEGIN
              SELECT ID_SEDE INTO v_id_sede
              FROM SEDE
              WHERE p_id_sede=TO_NUMBER(ID_SEDE);
              
              SELECT COUNT(*)
              INTO v_cantOrdTotal
              FROM ORDEN_PEDIDO
              WHERE v_id_sede=ID_SEDE;
              
              SELECT COUNT(*)
              INTO v_cantOrdEsp
              FROM ORDEN_PEDIDO
              WHERE v_id_sede=ID_SEDE and
                    FECHA_ENTREGA is not null and
                    (FECHA_ENTREGA-FECHA_REGISTRO)<=30;
              
              IF (v_cantOrdTotal<>0) THEN
                    v_porc:=(NVL(v_cantOrdEsp,0)/NVL(v_cantOrdTotal,0))*100;
              ELSE
                    RETURN 0;
              END IF;
              RETURN ROUND(NVL(v_porc,0),0);
          EXCEPTION
                WHEN NO_DATA_FOUND THEN
                    RETURN 0;
          END;

-- Caso 1:
SELECT fn_eficiencia_entrega_sede(1) FROM DUAL;

-- Caso 2:
SELECT fn_eficiencia_entrega_sede(7) FROM DUAL;

-- Caso 3:
SELECT fn_eficiencia_entrega_sede(999) FROM DUAL;


--PREGUNTA 3
SET SERVEROUT ON;

CREATE OR REPLACE PROCEDURE sp_registrar_cliente
       (P_ID_CLIENTE NUMBER,P_RAZON_SOCIAL CHAR,P_RUC CHAR,P_TELEFONO CHAR,
       P_CORREO CHAR,P_DIRECCION_FISCAL CHAR)
      IS
            v_id_cliente CLIENTE.ID_CLIENTE%TYPE;
      BEGIN
          SELECT ID_CLIENTE INTO v_id_cliente
          FROM CLIENTE
          WHERE P_ID_CLIENTE=TO_NUMBER(ID_CLIENTE);
          dbms_output.put_line( 'Error: El ID de cliente ' || P_ID_CLIENTE
                || ' ya existe');
          
          IF(v_id_cliente <> null) THEN
            dbms_output.put_line( 'Error: El ID de cliente ' || p_id_cliente
                || ' ya existe');
            end if;
      
      END;
      
-- Caso 1:
EXEC sp_registrar_cliente(9, 'Transportes Express', '20505050505', '998877665',
'contact@express.com', 'Av. Principal 123');

-- Caso 2:
EXEC sp_registrar_cliente(10, NULL, NULL, NULL, NULL, NULL);

-- Caso 3:
EXEC sp_registrar_cliente(11, '', '', '', '', '');

-- Caso 3:
EXEC sp_registrar_cliente(1, 'Nueva Empresa', '20606060606', '999999999','info@nueva.com', 'Calle Nueva 789');


--PREGUNTA 4
CREATE OR REPLACE PROCEDURE sp_cliente_mas_pedidos
       (p_anio NUMBER)
      IS
          v_anio NUMBER;
          v_cantped NUMBER:=0;
      BEGIN
          SELECT extract( year from FECHA_REGISTRO ) INTO v_anio
          FROM ORDEN_PEDIDO
          WHERE p_anio<=extract( year from FECHA_REGISTRO );
          
          SELECT COUNT (*) into v_cantped
          FROM ORDEN_PEDIDO
          WHERE p_anio=extract( year from FECHA_REGISTRO );
          
          IF(v_cantped = 0) THEN
            dbms_output.put_line( 'No se encontraron pedidos en el año' || p_anio);
            end if;
      
      EXCEPTION
          WHEN NO_DATA_FOUND THEN
               dbms_output.put_line( 'Error: El año puede ser futuro');
      END;
      
      dbms_output.put_line( 'No se encontraron pedidos en el año '
                    || p_anio);
      
EXEC sp_cliente_mas_pedidos(2024);
      
EXEC sp_cliente_mas_pedidos(2000);

EXEC sp_cliente_mas_pedidos(2025);


--PREGUNTA 5
CREATE OR REPLACE PROCEDURE sp_total_buses_pedidos
       (P_ID_SEDE NUMBER,P_MES CHAR,P_TIPO_BUS NUMBER)
      IS
          v_id_sede SEDE.ID_SEDE%TYPE;
          v_totalbuses NUMBER;
          v_ultimafecha DATE;
          v_nombreSede VARCHAR2(100);
          v_nombreBus VARCHAR2(100);
          e_noSede EXCEPTION;
          e_noTipo EXCEPTION;
      BEGIN
          SELECT ID_SEDE,NOMBRE_SEDE
          INTO v_id_sede,v_nombreSede
          FROM sede
          WHERE P_ID_SEDE=TO_NUMBER(ID_SEDE);
          IF v_nombreSede IS NULL then
					RAISE e_noSede;
            end if;
          
          SELECT nombre
          INTO v_nombreBus
          FROM TIPO_BUS
          WHERE P_TIPO_BUS=TO_NUMBER(ID_TIPO_BUS);
          
          dbms_output.put_line( 'RESUMEN DE BUSES PEDIDOS');
          dbms_output.put_line( '--------------------------------------');
          dbms_output.put_line( 'Sede: ' || v_nombreSede);
          dbms_output.put_line( 'Tipo de Bus: ' || v_nombreBus);
          dbms_output.put_line( 'Total pedidos: ' || NVL(v_totalbuses,0));
          
          
      EXCEPTION
          WHEN no_data_found THEN
               dbms_output.put_line( 'Error: La sede no existe');
          WHEN e_noTipo THEN
               dbms_output.put_line( 'Error: El tipo de bus no existe');
      END;
      
EXEC sp_total_buses_pedidos(5,'03/2024',1);

EXEC sp_total_buses_pedidos(999,'03/2024',1);

EXEC sp_total_buses_pedidos(1,'03/2024',1);

EXEC sp_total_buses_pedidos(1,'01/2023',2);


--PREGUNTA 6
CREATE OR REPLACE PROCEDURE sp_resumen_cliente
       (P_ID_CLIENTE NUMBER)
      IS
          v_id_cliente CLIENTE.ID_CLIENTE%TYPE;
          v_totalbuses NUMBER;
          v_ultimafecha DATE;
          v_nombrecli VARCHAR2(100);
      BEGIN
          SELECT ID_CLIENTE,RAZON_SOCIAL
          INTO v_id_cliente,v_nombrecli
          FROM CLIENTE
          WHERE P_ID_CLIENTE=TO_NUMBER(ID_CLIENTE);
          
          SELECT SUM(NVL(D.CANTIDAD,0)),MAX(O.FECHA_REGISTRO),
          INTO v_totalbuses,v_ultimafecha
          FROM  CLIENTE C,ORDEN_PEDIDO O,DETALLE_ORD_PEDIDO D
          WHERE v_id_cliente=O.ID_CLIENTE AND O.ID_ORDEN_PEDIDO=D.ID_ORDEN_PEDIDO;
          
          dbms_output.put_line( 'RESUMEN COMERCIAL DE CLIENTE');
          dbms_output.put_line( '--------------------------------------');
          dbms_output.put_line( 'Cliente: ' || v_nombrecli);
          dbms_output.put_line( 'Total buses pedidos: ' || NVL(v_totalbuses,0));
          if(v_totalbuses<>0) then
                dbms_output.put_line( 'Último pedido: ' ||
                TO_DATE(v_ultimafecha,'dd/mm/yyyy'));
          else
                dbms_output.put_line( 'Último pedido: Sin pedidos registrados');
          end if;
          
      EXCEPTION
          WHEN NO_DATA_FOUND THEN
               dbms_output.put_line( 'Error: Cliente con ID ' || P_ID_CLIENTE
                || ' no existe');
      END;

EXEC sp_resumen_cliente(4);

EXEC sp_resumen_cliente(8);

EXEC sp_resumen_cliente(999);
