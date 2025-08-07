--ITEM a------------------------------------------------------------------------
SELECT DISTINCT C.CCID,C.CCNOMBRE AS CLIENTE,C.CCINDUSTRIA AS INDUSTRIA
FROM E1_CLIENTECORP C,E1_APARTAMENTO A
WHERE C.REFERCCID IS NOT NULL AND C.CCID=A.CCID
ORDER BY 1;

--ITEM b------------------------------------------------------------------------
SELECT  I.INSID AS COD_INSPECTOR,I.INSNOMBRE AS NOMBRE,
        TO_CHAR(A.SGTEINSP,'MM') AS MES,COUNT (A.SGTEINSP) AS CANTIDAD
FROM E1_INSPECTOR I,E1_INSPECCIONA A
WHERE I.INSID=A.IDINSPECTOR AND TO_CHAR(A.SGTEINSP,'YYYY-MM-DD')>'2022-05-15'
GROUP BY I.INSID,I.INSNOMBRE,TO_CHAR(A.SGTEINSP,'MM')
ORDER BY I.INSID,TO_CHAR(A.SGTEINSP,'MM');

--ITEM c------------------------------------------------------------------------
SELECT E.EDIFICIOID,A.APARTNO AS NRO_APARTAMENTO
FROM E1_EDIFICIO E,E1_APARTAMENTO A,E1_CLIENTECORP C
WHERE E.EDIFICIOID=A.EDIFICIOID AND C.CCID=A.CCID AND C.CCNOMBRE LIKE 'SPOTI5'
ORDER BY E.EDIFICIOID,A.APARTNO;

--ITEM d------------------------------------------------------------------------
SELECT DISTINCT P.PID,P.PNOMBRE AS NOMBRES
FROM E1_PERSONAL P,E1_LIMPIEZA L,E1_APARTAMENTO A,E1_CLIENTECORP C
WHERE P.PID=L.PID AND L.APARTNO=A.APARTNO AND A.CCID=C.CCID AND C.CCNOMBRE LIKE 'BARCELONA'
ORDER BY 1 DESC;

--EJERCICIOS EXTRAS-------------------------------------------------------------

--EJERCICIO 1-------------------------------------------------------------------
--(1.0 punto) Crea un índice en la tabla de inspecciones que permita optimizar
--las consultas que buscan inspecciones realizadas después de una fecha
--específica. Luego, elabora una consulta que liste todos los inspectores que
--tienen inspecciones programadas después del 1 de junio de 2023, mostrando la
--cantidad de inspecciones que deben realizar en cada mes.--

CREATE INDEX 
