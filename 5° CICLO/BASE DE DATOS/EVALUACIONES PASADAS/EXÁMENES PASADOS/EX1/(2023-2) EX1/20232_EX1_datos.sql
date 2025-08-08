insert into EX1_departamentoperu (iddepartamento,nombredepartamento) values ('001','Lima'); 

insert into EX1_provincia (idprovincia,nombreprovincia,iddepartamento) values ('001','Lima','001');
insert into EX1_provincia (idprovincia,nombreprovincia,iddepartamento) values ('002','Callao','001');

insert into EX1_distrito (iddistrito,nombre,idprovincia) values ('001','San Miguel','001');
insert into EX1_distrito (iddistrito,nombre,idprovincia) values ('002','Pueblo Libre','001');
insert into EX1_distrito (iddistrito,nombre,idprovincia) values ('003','Magdalena','001');
insert into EX1_distrito (iddistrito,nombre,idprovincia) values ('004','Jesús María','001');
insert into EX1_distrito (iddistrito,nombre,idprovincia) values ('005','San Martín de Porras','001');
insert into EX1_distrito (iddistrito,nombre,idprovincia) values ('006','Lince','001');
insert into EX1_distrito (iddistrito,nombre,idprovincia) values ('007','San Borja','001');
insert into EX1_distrito (iddistrito,nombre,idprovincia) values ('008','Callao','002');

insert into EX1_tipocochera (idtipocochera,nombre) values ('0','Sin cochera');
insert into EX1_tipocochera (idtipocochera,nombre) values ('1','Sin techo');
insert into EX1_tipocochera (idtipocochera,nombre) values ('2','Techada');

insert into EX1_tipoinmueble (idtipoinmueble,nombre) values ('00','Casa');
insert into EX1_tipoinmueble (idtipoinmueble,nombre) values ('01','Departamento');
insert into EX1_tipoinmueble (idtipoinmueble,nombre) values ('02','Terreno');

insert into EX1_tipopago (idtipopago,descripcion) values ('00','Al contado');
insert into EX1_tipopago (idtipopago,descripcion) values ('01','A plazos');
insert into EX1_tipopago (idtipopago,descripcion) values ('02','Crédito hipotecario');
insert into EX1_tipopago (idtipopago,descripcion) values ('03','Crédito Mi Vivienda');

Insert into EX1_vendedor
   (IDVENDEDOR, NOMBREVENDEDOR, TELEFONO, EMAIL, EDAD, COMISION)
 Values
   ('00000001', 'MONZON TORRES, LUIS', '98475639', 'ltorres@pucp.edu.pe.com', 40, 0.05);
Insert into EX1_vendedor
   (IDVENDEDOR, NOMBREVENDEDOR, TELEFONO, EMAIL, EDAD, COMISION)
 Values
   ('00000002', 'TORERO MONTES, CARMELA', '98745863', 'ctorero@pucp.edu.pe.com', 35, 0.06);
Insert into EX1_vendedor
   (IDVENDEDOR, IDSUPERVISOR, NOMBREVENDEDOR, TELEFONO, EMAIL, EDAD, COMISION)
 Values
   ('00000003', '00000001', 'CALIXTO GARCIA, SUSAN', '98574123', 'scalixto@pucp.edu.pe.com', 30, 0.04);
Insert into EX1_vendedor
   (IDVENDEDOR, IDSUPERVISOR, NOMBREVENDEDOR, TELEFONO, EMAIL, EDAD, COMISION)
 Values
   ('00000004', '00000001', 'CASTILLO HERRERA, DANIEL', '96325874', 'dcastillo@pucp.edu.pe.com', 36, 0.09);
Insert into EX1_vendedor
   (IDVENDEDOR, IDSUPERVISOR, NOMBREVENDEDOR, TELEFONO, EMAIL, EDAD, COMISION)
 Values
   ('00000005', '00000002', 'BONILLA CHAVARRI, EDUARDO', '96874852', 'ebonilla@pucp.edu.pe.com', 47, 0.05);
Insert into EX1_vendedor
   (IDVENDEDOR, IDSUPERVISOR, NOMBREVENDEDOR, TELEFONO, EMAIL, EDAD, COMISION)
 Values
   ('00000006', '00000002', 'CASTRO VILCA, JANET', '98657484', 'jcastro@pucp.edu.pe.com', 35, 0.05);


insert into EX1_inmueble (idinmueble,direccion,precio,areaterreno,areaconstruccion,numbanhos,numcocheras,idtipoinmueble,iddistrito,idvendedor,idtipocochera,anhoconstruccion,descripcioninmueble,vendido) 
values ('00000001','Ca. Los Rosales 114',50000,190,218,2,1,'00','002','00000005','1',1982,'Con 3 dormitorios, cuarto de servicio','1');
insert into EX1_inmueble (idinmueble,direccion,precio,areaterreno,areaconstruccion,numbanhos,numcocheras,idtipoinmueble,iddistrito,idvendedor,idtipocochera,anhoconstruccion,descripcioninmueble,vendido) 
values ('00000002','Av. San Felipe 215 - dpto 102',35000,100,100,1,0,'01','004','00000002','0',1998,'Cocina amoblada','1');
insert into EX1_inmueble (idinmueble,direccion,precio,areaterreno,areaconstruccion,numbanhos,numcocheras,idtipoinmueble,iddistrito,idvendedor,idtipocochera,anhoconstruccion,descripcioninmueble,vendido) 
values ('00000003','Av. Pershing 320',80000,1000,0,0,0,'02','004','00000002','0',0,'En zona residencial','0');
insert into EX1_inmueble (idinmueble,direccion,precio,areaterreno,areaconstruccion,numbanhos,numcocheras,idtipoinmueble,iddistrito,idvendedor,idtipocochera,anhoconstruccion,descripcioninmueble,vendido) 
values ('00000004','Jr. José Aguirre 629',43500,250,215,3,2,'00','007','00000001','2',1990,'Finos acabados, con area de servicio','1');
insert into EX1_inmueble (idinmueble,direccion,precio,areaterreno,areaconstruccion,numbanhos,numcocheras,idtipoinmueble,iddistrito,idvendedor,idtipocochera,anhoconstruccion,descripcioninmueble,vendido) 
values ('00000005','Av. San Juan 165 - dpto A',35000,100,100,1,0,'01','004','00000001','0',1998,'Con patio y lavadero','0');

insert into EX1_inmueble (idinmueble,direccion,precio,areaterreno,areaconstruccion,numbanhos,numcocheras,idtipoinmueble,iddistrito,idvendedor,idtipocochera,anhoconstruccion,descripcioninmueble,vendido) 
values ('00000006','Ca. La Madrileña 231',45000,180,218,2,1,'00','002','00000003','1',1992,'Con 4 dormitorios','1');
insert into EX1_inmueble (idinmueble,direccion,precio,areaterreno,areaconstruccion,numbanhos,numcocheras,idtipoinmueble,iddistrito,idvendedor,idtipocochera,anhoconstruccion,descripcioninmueble,vendido) 
values ('00000007','Av. Pershing 320',10000,500,0,0,0,'02','007','00000002','0',0,'En zona industrial','1');
insert into EX1_inmueble (idinmueble,direccion,precio,areaterreno,areaconstruccion,numbanhos,numcocheras,idtipoinmueble,iddistrito,idvendedor,idtipocochera,anhoconstruccion,descripcioninmueble,vendido) 
values ('00000008','Psje. Artemisa 150',15000,190,218,3,2,'00','006','00000005','2',1970,'Con 3 dormitorios, cuarto de servicio','1');
insert into EX1_inmueble (idinmueble,direccion,precio,areaterreno,areaconstruccion,numbanhos,numcocheras,idtipoinmueble,iddistrito,idvendedor,idtipocochera,anhoconstruccion,descripcioninmueble,vendido) 
values ('00000009','Ca. Los Fresnos - dpto 401B',46000,150,150,2,1,'01','004','00000001','1',1985,'Cocina amoblada','0');
insert into EX1_inmueble (idinmueble,direccion,precio,areaterreno,areaconstruccion,numbanhos,numcocheras,idtipoinmueble,iddistrito,idvendedor,idtipocochera,anhoconstruccion,descripcioninmueble,vendido) 
values ('00000010','Ca. Los Duraznos 631',68000,270,360,4,3,'00','006','00000004','1',2000,'Con 4 dormitorios, estudio y salón familiar','1');

insert into EX1_inmueble (idinmueble,direccion,precio,areaterreno,areaconstruccion,numbanhos,numcocheras,idtipoinmueble,iddistrito,idvendedor,idtipocochera,anhoconstruccion,descripcioninmueble,vendido) 
values ('00000011','Ca. León García 241',25000,180,218,2,1,'00','001','00000001','1',1992,'Con 4 dormitorios','1');
insert into EX1_inmueble (idinmueble,direccion,precio,areaterreno,areaconstruccion,numbanhos,numcocheras,idtipoinmueble,iddistrito,idvendedor,idtipocochera,anhoconstruccion,descripcioninmueble,vendido) 
values ('00000012','Psje. Los Cascos 320',10000,500,0,0,0,'02','005','00000004','0',0,'En zona industrial','0');
insert into EX1_inmueble (idinmueble,direccion,precio,areaterreno,areaconstruccion,numbanhos,numcocheras,idtipoinmueble,iddistrito,idvendedor,idtipocochera,anhoconstruccion,descripcioninmueble,vendido) 
values ('00000013','Psje. Los Molinos 150',15000,190,150,3,2,'00','006','00000006','2',1970,'Con 3 dormitorios, cuarto de servicio','1');
insert into EX1_inmueble (idinmueble,direccion,precio,areaterreno,areaconstruccion,numbanhos,numcocheras,idtipoinmueble,iddistrito,idvendedor,idtipocochera,anhoconstruccion,descripcioninmueble,vendido) 
values ('00000014','Av. Martinelli 472 - dpto 201',46000,150,150,2,1,'01','004','00000005','1',1985,'Cocina amoblada','0');
insert into EX1_inmueble (idinmueble,direccion,precio,areaterreno,areaconstruccion,numbanhos,numcocheras,idtipoinmueble,iddistrito,idvendedor,idtipocochera,anhoconstruccion,descripcioninmueble,vendido) 
values ('00000015','Ca. Los Duraznos 631',68000,270,360,4,3,'00','006','00000003','1',2000,'Con 4 dormitorios, estudio y salón familiar','1');

insert into EX1_casa (idinmueble,numpisos) values ('00000001',2);
insert into EX1_casa (idinmueble,numpisos) values ('00000004',1);
insert into EX1_casa (idinmueble,numpisos) values ('00000006',2);
insert into EX1_casa (idinmueble,numpisos) values ('00000008',3);
insert into EX1_casa (idinmueble,numpisos) values ('00000010',2);
insert into EX1_casa (idinmueble,numpisos) values ('00000011',2);
insert into EX1_casa (idinmueble,numpisos) values ('00000013',1);
insert into EX1_casa (idinmueble,numpisos) values ('00000015',3);

insert into EX1_departamento (idinmueble,ubicacionpiso) values ('00000002',2);
insert into EX1_departamento (idinmueble,ubicacionpiso) values ('00000005',1);
insert into EX1_departamento (idinmueble,ubicacionpiso) values ('00000009',4);
insert into EX1_departamento (idinmueble,ubicacionpiso) values ('00000014',2);

insert into EX1_terreno (idinmueble,indtieneagua,indtieneluz,indtienedesague) values ('00000003','1','1','1');
insert into EX1_terreno (idinmueble,indtieneagua,indtieneluz,indtienedesague) values ('00000007','1','1','1');
insert into EX1_terreno (idinmueble,indtieneagua,indtieneluz,indtienedesague) values ('00000012','0','1','1');


INSERT INTO EX1_CLIENTE ( IDCLIENTE, NOMBRE, TELEFONO, DIRECCION,MONTODIPONIBLE ) VALUES ( 
'00000001', 'LOPES TORRES, LUIS', '2536897', 'JR. HUARAZ 331 - MIRAFLORES', 52000); 
INSERT INTO EX1_CLIENTE ( IDCLIENTE, NOMBRE, TELEFONO, DIRECCION,MONTODIPONIBLE ) VALUES ( 
'00000002', 'CUBA ALVARADO, MARIA', '5897416', 'AV SAN BORJA SUR 254 -SAN BORJA', 100000); 
INSERT INTO EX1_CLIENTE ( IDCLIENTE, NOMBRE, TELEFONO, DIRECCION,MONTODIPONIBLE ) VALUES ( 
'00000003', 'LEYVA SOLE, DAVID', '98174358', 'AV. PARDO 358 - MIRAFLORES', 65000); 
INSERT INTO EX1_CLIENTE ( IDCLIENTE, NOMBRE, TELEFONO, DIRECCION,MONTODIPONIBLE ) VALUES ( 
'00000004', 'ALFARO AREVALO, PATRICIA', '4785936', 'JR. PILCOMAYO 4789 - SAN LUIS', 35000); 
INSERT INTO EX1_CLIENTE ( IDCLIENTE, NOMBRE, TELEFONO, DIRECCION,MONTODIPONIBLE ) VALUES ( 
'00000005', 'ALVARADO RUIZ, ROCIO', '98745782', 'JR LOPEZ DE AYALA 984 - SAN MIGUEL', 42000); 
INSERT INTO EX1_CLIENTE ( IDCLIENTE, NOMBRE, TELEFONO, DIRECCION,MONTODIPONIBLE ) VALUES ( 
'00000006', 'AYALA LOPEZ, JOSE ', '98542874', 'AV. ANGAMOS 2598 - MIRAFLORES', 80000); 
INSERT INTO EX1_CLIENTE ( IDCLIENTE, NOMBRE, TELEFONO, DIRECCION,MONTODIPONIBLE ) VALUES ( 
'00000007', 'BINASCO BLONDET, ANTONIO', '4587369', 'JR AREQUIPA 3589 - PUEBLO LIBRE', 60000); 
INSERT INTO EX1_CLIENTE ( IDCLIENTE, NOMBRE, TELEFONO, DIRECCION,MONTODIPONIBLE ) VALUES ( 
'00000008', 'LLATAS VILLANUEVA, MARILU', '9836510', 'AV. PRECURSORES 450 - SAN MIGUEL', 25000); 
INSERT INTO EX1_CLIENTE ( IDCLIENTE, NOMBRE, TELEFONO, DIRECCION, MONTODIPONIBLE ) VALUES ( 
'00000009', 'LLANOS LINARES, JESSICA', '92156748', 'AV LA PAZ 358 - SAN MIGUEL', 65000); 
INSERT INTO EX1_CLIENTE ( IDCLIENTE, NOMBRE, TELEFONO, DIRECCION,MONTODIPONIBLE ) VALUES ( 
'00000010', 'GRADOS GUTIERREZ, KATHERINE', '3256897', 'AV JORGE CASTRO 3548 - CALLAO', 150000); 
INSERT INTO EX1_CLIENTE ( IDCLIENTE, NOMBRE, TELEFONO, DIRECCION, MONTODIPONIBLE ) VALUES ( 
'00000011', 'GAMERO PAREDES, KATIA', '957841258', 'AV HUACAR 345 - JESUS MARIA', 75000); 
INSERT INTO EX1_CLIENTE ( IDCLIENTE, NOMBRE, TELEFONO, DIRECCION,MONTODIPONIBLE ) VALUES ( 
'00000012', 'CORDOVA SIFUENTES, PAOLA', '98745326', 'AV CAYETANO HEREDIA 458 - MONTERRICO', 50000); 
INSERT INTO EX1_CLIENTE ( IDCLIENTE, NOMBRE, TELEFONO, DIRECCION,MONTODIPONIBLE ) VALUES ( 
'00000013', 'TORRES SOLANO, MARGARITA', '2568749', 'AV. CORREGIDOR 258 - LA MOLINA', 55000); 

insert into EX1_contratoventa values ('00000001','00','00000004','00000002', to_date('05/03/2004','dd-mm-yyyy'),34000,0);
insert into EX1_contratoventa values ('00000002','00','00000003','00000001', to_date('07/03/2004','dd-mm-yyyy'),45000,0);
insert into EX1_contratoventa values ('00000003','01','00000002','00000006', to_date('25/03/2004','dd-mm-yyyy'),45000,24);
insert into EX1_contratoventa values ('00000004','01','00000001','00000004', to_date('28/03/2004','dd-mm-yyyy'),43000,12);
insert into EX1_contratoventa values ('00000005','00','00000007','00000010', to_date('08/04/2004','dd-mm-yyyy'),65000,0);
insert into EX1_contratoventa values ('00000006','01','00000008','00000008', to_date('12/04/2004','dd-mm-yyyy'),15000,10);
insert into EX1_contratoventa values ('00000007','00','00000009','00000007', to_date('13/04/2004','dd-mm-yyyy'),10000,0);
insert into EX1_contratoventa values ('00000008','00','00000006','00000011', to_date('14/04/2004','dd-mm-yyyy'),24000,0);
insert into EX1_contratoventa values ('00000009','00','00000011','00000013', to_date('15/04/2004','dd-mm-yyyy'),15000,0);
insert into EX1_contratoventa values ('00000010','01','00000013','00000015', to_date('16/04/2004','dd-mm-yyyy'),68000,30);

 commit;

