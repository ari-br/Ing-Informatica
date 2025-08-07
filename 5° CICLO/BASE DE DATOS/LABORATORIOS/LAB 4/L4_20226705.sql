-- Pregunta 1
SET SERVEROUTPUT ON;

CREATE OR REPLACE PROCEDURE sp_actualiza_precio_venta
IS
    CURSOR c_det_ord_ped
    IS
    SELECT *
    FROM DETALLE_ORD_PEDIDO
    ORDER BY ID_DETALLE_PEDIDO;
    r_det_ord_ped c_det_ord_ped%rowtype;
    v_costo NUMBER:=0;
BEGIN
    for r_det_ord_ped in c_det_ord_ped loop
        SELECT COSTO_PRODUCCION_UNITARIO INTO v_costo
        FROM ORDEN_PRODUCCION
        WHERE id_orden_produccion=r_det_ord_ped.ID_ORDEN_PRODUCCION;
        
        UPDATE detalle_ord_pedido
        SET precio_venta_unitario=v_costo*1.3
        WHERE id_orden_pedido=r_det_ord_ped.id_orden_pedido AND
            ID_ORDEN_PRODUCCION=r_det_ord_ped.id_orden_produccion;
    end loop;
EXCEPTION
    WHEN NO_DATA_FOUND THEN
        dbms_output.put_line('Error: no se encontro la orden de producción correspondiente');
END;

EXEC sp_actualiza_precio_venta;

SELECT * FROM DETALLE_ORD_PEDIDO
ORDER BY to_number(ID_DETALLE_PEDIDO);


-- Pregunta 2
SET SERVEROUTPUT ON;

CREATE OR REPLACE PROCEDURE sp_imprimir_detalle_pedido
    (p_id_pedido NUMBER)
IS
    CURSOR c_det_ord_ped
    IS
    SELECT *
    FROM DETALLE_ORD_PEDIDO
    ORDER BY ID_TIPO_BUS,CANTIDAD;
    v_fecha_reg ORDEN_PEDIDO.FECHA_REGISTRO%TYPE;
    v_fecha_ent ORDEN_PEDIDO.FECHA_ENTREGA%TYPE;
    v_bus TIPO_BUS%ROWTYPE;
BEGIN
    SELECT FECHA_REGISTRO,FECHA_ENTREGA INTO v_fecha_reg,v_fecha_ent
    FROM ORDEN_PEDIDO
    WHERE ID_ORDEN_PEDIDO=p_id_pedido;
    dbms_output.put_line('Pedido Nro: '||p_id_pedido);
    dbms_output.put_line('Fecha de Registro: '||TO_CHAR(v_fecha_reg,'DD/MM/YYYY'));
    dbms_output.put_line('Fecha de Entrega: '||TO_CHAR(v_fecha_ent,'DD/MM/YYYY'));
    dbms_output.put_line('Detalle de artículos');
    dbms_output.put_line('****************************');
    dbms_output.put_line('ID TIPO BUS - NOMBRE TIPO BUS - CANTIDAD - PRECIO VENTA UNITARIO');
    dbms_output.put_line('************************************************************************');
    for r_det_ord_ped in c_det_ord_ped loop
        IF r_det_ord_ped.id_orden_pedido=p_id_pedido THEN
            SELECT * INTO v_bus
            FROM TIPO_BUS
            WHERE ID_TIPO_BUS=r_det_ord_ped.id_tipo_bus;
            dbms_output.put_line(v_bus.id_tipo_bus||' - '||TRIM(v_bus.nombre)||' - '||
                r_det_ord_ped.cantidad||' - '||r_det_ord_ped.precio_venta_unitario);
        END IF;
    end loop;
EXCEPTION
    WHEN NO_DATA_FOUND THEN
        dbms_output.put_line('Error: El Pedido no existe');
END;
      
EXEC sp_imprimir_detalle_pedido(10);
EXEC sp_imprimir_detalle_pedido(89);


-- Pregunta 3
CREATE OR REPLACE TRIGGER tr_actualizar_sede
BEFORE INSERT OR UPDATE ON SEDE
FOR EACH ROW
BEGIN
    IF(inserting)THEN
        :NEW.FECHA_CREACION:=sysdate;
    END IF;
	:NEW.FECHA_ULTIMA_MODIFICACION:=sysdate;
END;

insert into SEDE (id_sede, nombre_sede, distrito, provincia, area_sede, direccion, telefono)
values (9,'Almacen Lima Centro', 'Cercado de Lima', 'Lima', 1200, 'Av Andahuaylas 1258', '999654123');

SELECT *
FROM SEDE
WHERE ID_SEDE=9;


-- Pregunta 4
CREATE OR REPLACE TRIGGER tr_actualizar_precio
AFTER UPDATE OF COSTO_PRODUCCION_UNITARIO ON ORDEN_PRODUCCION
FOR EACH ROW
BEGIN
    UPDATE detalle_ord_pedido
    SET precio_venta_unitario=:NEW.COSTO_PRODUCCION_UNITARIO*1.3
    WHERE ID_ORDEN_PRODUCCION=:NEW.ID_ORDEN_PRODUCCION;
END;

update ORDEN_PRODUCCION
set costo_produccion_unitario=160000
where id_orden_produccion=5;

SELECT * FROM DETALLE_ORD_PEDIDO
WHERE id_orden_produccion=5
ORDER BY to_number(ID_DETALLE_PEDIDO);

