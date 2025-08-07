
DROP TABLE EX1_CONTRATOVENTA CASCADE CONSTRAINTS;

CREATE TABLE EX1_CONTRATOVENTA (
       NumContrato          CHAR(8) NOT NULL,
       IdTipoPago           CHAR(2) NOT NULL,
       IdCliente            CHAR(8) NOT NULL,
       IdInmueble           CHAR(8) NOT NULL,
       FechaVenta           DATE NOT NULL,
       Precio               NUMBER(8) NOT NULL,
       Cuotas               NUMBER(3) NOT NULL
);


ALTER TABLE EX1_CONTRATOVENTA
       ADD  ( CONSTRAINT XPKEX1_CONTRATOVENTA PRIMARY KEY (NumContrato) ) ;


DROP TABLE EX1_TIPOPAGO CASCADE CONSTRAINTS;

CREATE TABLE EX1_TIPOPAGO (
       IdTipoPago           CHAR(2) NOT NULL,
       Descripcion          VARCHAR2(100) NOT NULL
);


ALTER TABLE EX1_TIPOPAGO
       ADD  ( CONSTRAINT XPKEX1_TIPOPAGO PRIMARY KEY (IdTipoPago) ) ;


DROP TABLE EX1_CLIENTE CASCADE CONSTRAINTS;

CREATE TABLE EX1_CLIENTE (
       IdCliente            CHAR(8) NOT NULL,
       Nombre               VARCHAR2(100) NOT NULL,
       Telefono             VARCHAR2(10) NOT NULL,
       Direccion            VARCHAR2(200) NOT NULL,
       MontoDiponible       NUMBER(8) NOT NULL
);


ALTER TABLE EX1_CLIENTE
       ADD  ( CONSTRAINT XPKEX1_CLIENTE PRIMARY KEY (IdCliente) ) ;


DROP TABLE EX1_INMUEBLE CASCADE CONSTRAINTS;

CREATE TABLE EX1_INMUEBLE (
       IdInmueble           CHAR(8) NOT NULL,
       Direccion            VARCHAR2(100) NOT NULL,
       Precio               NUMBER(6) NOT NULL,
       AreaTerreno          NUMBER(4) NOT NULL,
       AreaConstruccion     NUMBER(4) NOT NULL,
       NumBanhos            NUMBER(2) NOT NULL,
       NumCocheras          NUMBER(2) NOT NULL,
       IdTipoInmueble       CHAR(2) NOT NULL,
       IdDistrito           CHAR(3) NOT NULL,
       IdVendedor           CHAR(8) NOT NULL,
       IdTipoCochera        CHAR(1) NOT NULL,
       AnhoConstruccion     NUMBER(4) NOT NULL,
       DescripcionInmueble  VARCHAR2(100) NULL,
       Vendido              CHAR(1) NOT NULL
);


ALTER TABLE EX1_INMUEBLE
       ADD  ( CONSTRAINT XPKEX1_INMUEBLE PRIMARY KEY (IdInmueble) ) ;


DROP TABLE EX1_TIPOCOCHERA CASCADE CONSTRAINTS;

CREATE TABLE EX1_TIPOCOCHERA (
       IdTipoCochera        CHAR(1) NOT NULL,
       Nombre               VARCHAR2(15) NOT NULL
);


ALTER TABLE EX1_TIPOCOCHERA
       ADD  ( CONSTRAINT XPKEX1_TIPOCOCHERA PRIMARY KEY (IdTipoCochera) ) ;


DROP TABLE EX1_VENDEDOR CASCADE CONSTRAINTS;

CREATE TABLE EX1_VENDEDOR (
       IdVendedor           CHAR(8) NOT NULL,
       idSupervisor         CHAR(8) NULL,
       NombreVendedor       VARCHAR2(100) NOT NULL,
       Telefono             VARCHAR2(10) NOT NULL,
       EMail                VARCHAR2(50) NOT NULL,
       Edad                 NUMBER(3) NOT NULL,
       Comision             NUMBER NULL
);


ALTER TABLE EX1_VENDEDOR
       ADD  ( CONSTRAINT XPKEX1_VENDEDOR PRIMARY KEY (IdVendedor) ) ;


DROP TABLE EX1_DISTRITO CASCADE CONSTRAINTS;

CREATE TABLE EX1_DISTRITO (
       IdDistrito           CHAR(3) NOT NULL,
       Nombre               VARCHAR2(50) NOT NULL,
       IdProvincia          CHAR(3) NOT NULL
);


ALTER TABLE EX1_DISTRITO
       ADD  ( CONSTRAINT XPKEX1_DISTRITO PRIMARY KEY (IdDistrito) ) ;


DROP TABLE EX1_PROVINCIA CASCADE CONSTRAINTS;

CREATE TABLE EX1_PROVINCIA (
       IdProvincia          CHAR(3) NOT NULL,
       NombreProvincia      VARCHAR2(50) NOT NULL,
       IdDepartamento       CHAR(3) NOT NULL
);


ALTER TABLE EX1_PROVINCIA
       ADD  ( CONSTRAINT XPKEX1_PROVINCIA PRIMARY KEY (IdProvincia) ) ;


DROP TABLE EX1_DEPARTAMENTOPERU CASCADE CONSTRAINTS;

CREATE TABLE EX1_DEPARTAMENTOPERU (
       IdDepartamento       CHAR(3) NOT NULL,
       NombreDepartamento   VARCHAR2(50) NOT NULL
);


ALTER TABLE EX1_DEPARTAMENTOPERU
       ADD  ( CONSTRAINT XPKEX1_DEPARTAMENTOPERU PRIMARY KEY (
              IdDepartamento) ) ;


DROP TABLE EX1_TIPOINMUEBLE CASCADE CONSTRAINTS;

CREATE TABLE EX1_TIPOINMUEBLE (
       IdTipoInmueble       CHAR(2) NOT NULL,
       Nombre               VARCHAR2(50) NOT NULL
);


ALTER TABLE EX1_TIPOINMUEBLE
       ADD  ( CONSTRAINT XPKEX1_TIPOINMUEBLE PRIMARY KEY (
              IdTipoInmueble) ) ;


DROP TABLE EX1_TERRENO CASCADE CONSTRAINTS;

CREATE TABLE EX1_TERRENO (
       IdInmueble           CHAR(8) NOT NULL,
       IndTieneAgua         CHAR(1) NOT NULL,
       IndTieneLuz          CHAR(1) NOT NULL,
       IndTieneDesague      CHAR(1) NOT NULL
);


ALTER TABLE EX1_TERRENO
       ADD  ( CONSTRAINT XPKEX1_TERRENO PRIMARY KEY (IdInmueble) ) ;


DROP TABLE EX1_DEPARTAMENTO CASCADE CONSTRAINTS;

CREATE TABLE EX1_DEPARTAMENTO (
       IdInmueble           CHAR(8) NOT NULL,
       UbicacionPiso        NUMBER(2) NOT NULL
);


ALTER TABLE EX1_DEPARTAMENTO
       ADD  ( CONSTRAINT XPKEX1_DEPARTAMENTO PRIMARY KEY (IdInmueble) ) ;


DROP TABLE EX1_CASA CASCADE CONSTRAINTS;

CREATE TABLE EX1_CASA (
       IdInmueble           CHAR(8) NOT NULL,
       NumPisos             NUMBER(2) NOT NULL
);


ALTER TABLE EX1_CASA
       ADD  ( CONSTRAINT XPKEX1_CASA PRIMARY KEY (IdInmueble) ) ;


ALTER TABLE EX1_CONTRATOVENTA
       ADD  ( FOREIGN KEY (IdTipoPago)
                             REFERENCES EX1_TIPOPAGO ) ;


ALTER TABLE EX1_CONTRATOVENTA
       ADD  ( FOREIGN KEY (IdCliente)
                             REFERENCES EX1_CLIENTE ) ;


ALTER TABLE EX1_CONTRATOVENTA
       ADD  ( FOREIGN KEY (IdInmueble)
                             REFERENCES EX1_INMUEBLE ) ;


ALTER TABLE EX1_INMUEBLE
       ADD  ( FOREIGN KEY (IdTipoCochera)
                             REFERENCES EX1_TIPOCOCHERA ) ;


ALTER TABLE EX1_INMUEBLE
       ADD  ( FOREIGN KEY (IdVendedor)
                             REFERENCES EX1_VENDEDOR ) ;


ALTER TABLE EX1_INMUEBLE
       ADD  ( FOREIGN KEY (IdDistrito)
                             REFERENCES EX1_DISTRITO ) ;


ALTER TABLE EX1_INMUEBLE
       ADD  ( FOREIGN KEY (IdTipoInmueble)
                             REFERENCES EX1_TIPOINMUEBLE ) ;


ALTER TABLE EX1_VENDEDOR
       ADD  ( CONSTRAINT R_18
              FOREIGN KEY (idSupervisor)
                             REFERENCES EX1_VENDEDOR ) ;


ALTER TABLE EX1_DISTRITO
       ADD  ( FOREIGN KEY (IdProvincia)
                             REFERENCES EX1_PROVINCIA ) ;


ALTER TABLE EX1_PROVINCIA
       ADD  ( FOREIGN KEY (IdDepartamento)
                             REFERENCES EX1_DEPARTAMENTOPERU ) ;


ALTER TABLE EX1_TERRENO
       ADD  ( FOREIGN KEY (IdInmueble)
                             REFERENCES EX1_INMUEBLE ) ;


ALTER TABLE EX1_DEPARTAMENTO
       ADD  ( FOREIGN KEY (IdInmueble)
                             REFERENCES EX1_INMUEBLE ) ;


ALTER TABLE EX1_CASA
       ADD  ( FOREIGN KEY (IdInmueble)
                             REFERENCES EX1_INMUEBLE ) ;



