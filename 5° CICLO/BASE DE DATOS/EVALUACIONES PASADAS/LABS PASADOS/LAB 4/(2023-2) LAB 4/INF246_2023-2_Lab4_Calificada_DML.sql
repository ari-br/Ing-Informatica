insert into bs_categoria (idcategoria, descripcion, estado) values ('001', 'Moda casual', 'A');
insert into bs_categoria (idcategoria, descripcion, estado) values ('002', 'Moda elegante', 'A');
insert into bs_categoria (idcategoria, descripcion, estado) values ('003', 'Accesorios moda elegante', 'I');
insert into bs_categoria (idcategoria, descripcion, estado) values ('004', 'Moda deportiva', 'A');
insert into bs_categoria (idcategoria, descripcion, estado) values ('005', 'Ropa interior', 'A');
insert into bs_categoria (idcategoria, descripcion, estado) values ('006', 'Belleza', 'I');
insert into bs_categoria (idcategoria, descripcion, estado) values ('007', 'Salud', 'I');
insert into bs_categoria (idcategoria, descripcion, estado) values ('008', 'Maleteria', 'I');
insert into bs_categoria (idcategoria, descripcion, estado) values ('009', 'Higuiene', 'I');
INSERT INTO BS_CATEGORIA (IDCATEGORIA, DESCRIPCION, ESTADO) VALUES ('010', 'uniformes', 'A');
INSERT INTO BS_CATEGORIA (IDCATEGORIA, DESCRIPCION, ESTADO) VALUES ('011', 'abrigos', 'A');

Insert into BS_PERSONA (IDPERSONA,DOCIDENTIDAD,NOMBRES,PRIMERAPELLIDO,SEGUNDOAPELLIDO,FECHANACIMIENTO,CELULAR) values ('EMP001','8517236','Jorge Luis','Juarez','Gomez',to_date('15/04/85','DD/MM/RR'),'984172540');
Insert into BS_PERSONA (IDPERSONA,DOCIDENTIDAD,NOMBRES,PRIMERAPELLIDO,SEGUNDOAPELLIDO,FECHANACIMIENTO,CELULAR) values ('EMP002','79484720','Irma Mar�a','Ramirez','Lasso',to_date('12/09/87','DD/MM/RR'),'945721356');
Insert into BS_PERSONA (IDPERSONA,DOCIDENTIDAD,NOMBRES,PRIMERAPELLIDO,SEGUNDOAPELLIDO,FECHANACIMIENTO,CELULAR) values ('EMP003','64413166','Francisco','Torres','La Mar',to_date('27/09/89','DD/MM/RR'),'972471258');
Insert into BS_PERSONA (IDPERSONA,DOCIDENTIDAD,NOMBRES,PRIMERAPELLIDO,SEGUNDOAPELLIDO,FECHANACIMIENTO,CELULAR) values ('EMP004','5348569','Mario','Campos','Izquierdo',to_date('11/08/99','DD/MM/RR'),'952314781');
Insert into BS_PERSONA (IDPERSONA,DOCIDENTIDAD,NOMBRES,PRIMERAPELLIDO,SEGUNDOAPELLIDO,FECHANACIMIENTO,CELULAR) values ('EMP005','63681307','Mirna','Delgado','Zapata',to_date('18/01/98','DD/MM/RR'),'968111570');
Insert into BS_PERSONA (IDPERSONA,DOCIDENTIDAD,NOMBRES,PRIMERAPELLIDO,SEGUNDOAPELLIDO,FECHANACIMIENTO,CELULAR) values ('EMP006','4654668342','Oscar','Leon',null,to_date('30/07/03','DD/MM/RR'),'965877245');
Insert into BS_PERSONA (IDPERSONA,DOCIDENTIDAD,NOMBRES,PRIMERAPELLIDO,SEGUNDOAPELLIDO,FECHANACIMIENTO,CELULAR) values ('EMP007','46465234','Benjamin','Rios','Laos',to_date('11/03/01','DD/MM/RR'),'903657120');
Insert into BS_PERSONA (IDPERSONA,DOCIDENTIDAD,NOMBRES,PRIMERAPELLIDO,SEGUNDOAPELLIDO,FECHANACIMIENTO,CELULAR) values ('EMP008','36784582','Jackeline','Verano',null,to_date('09/05/05','DD/MM/RR'),'968547740');
Insert into BS_PERSONA (IDPERSONA,DOCIDENTIDAD,NOMBRES,PRIMERAPELLIDO,SEGUNDOAPELLIDO,FECHANACIMIENTO,CELULAR) values ('CLI001', 41258796, 'Pedro', 'Ore', NULL, to_date('29/01/05','DD/MM/RR'), 994531234);
Insert into BS_PERSONA (IDPERSONA,DOCIDENTIDAD,NOMBRES,PRIMERAPELLIDO,SEGUNDOAPELLIDO,FECHANACIMIENTO,CELULAR) values ('CLI002', 51469870, 'David', 'Torrealva', 'De los Montes', to_date('17/05/06', 'DD/MM/RR'),	999999999);
Insert into BS_PERSONA (IDPERSONA,DOCIDENTIDAD,NOMBRES,PRIMERAPELLIDO,SEGUNDOAPELLIDO,FECHANACIMIENTO,CELULAR) values ('CLI003', 52678419, 'Karina', 'Montessori', 'Ezquivel Ramirez', to_date('23/11/07', 'DD/MM/RR'),	927485110);
Insert into BS_PERSONA (IDPERSONA,DOCIDENTIDAD,NOMBRES,PRIMERAPELLIDO,SEGUNDOAPELLIDO,FECHANACIMIENTO,CELULAR) values ('CLI004', 52369759, 'Elio', 'Rivasplata', 'Jimenez', to_date('16/12/04', 'DD/MM/RR'), 963125741);
Insert into BS_PERSONA (IDPERSONA,DOCIDENTIDAD,NOMBRES,PRIMERAPELLIDO,SEGUNDOAPELLIDO,FECHANACIMIENTO,CELULAR) values ('CLI005', 53789004, 'Antonieta', 'Canchanya', 'Sotelo', to_date('03/06/01', 'DD/MM/RR'), 999999999);
Insert into BS_PERSONA (IDPERSONA,DOCIDENTIDAD,NOMBRES,PRIMERAPELLIDO,SEGUNDOAPELLIDO,FECHANACIMIENTO,CELULAR) values ('CLI006', 58910704, 'Milagritos', 'Cusihuaman De Lopez', 'Jimenez', NULL, 952327147);


insert into BS_Prenda (idPrenda, idCategoria, descripcion, color) VALUES (1, '001', 'Pantalon drill', 'azul');
insert into BS_Prenda (idPrenda, idCategoria, descripcion, color) VALUES (2, '001', 'Pantalon drill', 'negro');
insert into BS_Prenda (idPrenda, idCategoria, descripcion, color) VALUES (3, '001', 'Pantalon drill', 'verde');
insert into BS_Prenda (idPrenda, idCategoria, descripcion, color) VALUES (4, '001', 'Pantalon drill', 'caramelo');
insert into BS_Prenda (idPrenda, idCategoria, descripcion, color) VALUES (5, '001', 'Camisa cuello V', 'negro');
insert into BS_Prenda (idPrenda, idCategoria, descripcion, color) VALUES (6, '001', 'Camisa cuello tortuta', 'amarillo');
insert into BS_Prenda (idPrenda, idCategoria, descripcion, color) VALUES (7, '001', 'Camisa cuello tortuta', 'anaranjado');
insert into BS_Prenda (idPrenda, idCategoria, descripcion, color) VALUES (8, '001', 'Camisa cuello tortuta', 'negro');
insert into BS_Prenda (idPrenda, idCategoria, descripcion, color) VALUES (9, '001', 'Camisa cuello tortuta', 'azul');
insert into BS_Prenda (idPrenda, idCategoria, descripcion, color) VALUES (10, '001', 'Camisa cuello V', 'celeste');
insert into BS_Prenda (idPrenda, idCategoria, descripcion, color) VALUES (11, '001', 'Camisa cuello V', 'blanco');
insert into BS_Prenda (idPrenda, idCategoria, descripcion, color) VALUES (12, '001', 'Camisa cuello V', 'lila');
insert into BS_Prenda (idPrenda, idCategoria, descripcion, color) VALUES (13, '001', 'Falda a cuadros', 'rojo');
insert into BS_Prenda (idPrenda, idCategoria, descripcion, color) VALUES (14, '001', 'Falda a cuadros', 'blanco');
insert into BS_Prenda (idPrenda, idCategoria, descripcion, color) VALUES (15, '001', 'Falda a cuadros', 'negro');
insert into BS_Prenda (idPrenda, idCategoria, descripcion, color) VALUES (16, '001', 'Falda a cuadros', 'azul');


insert into BS_Prenda (idPrenda, idCategoria, descripcion, color) VALUES (17, '002', 'Vestido largo', 'azul');
insert into BS_Prenda (idPrenda, idCategoria, descripcion, color) VALUES (18, '002', 'Vestido largo', 'negro');
insert into BS_Prenda (idPrenda, idCategoria, descripcion, color) VALUES (19, '002', 'Vestido largo', 'rojo');
insert into BS_Prenda (idPrenda, idCategoria, descripcion, color) VALUES (20, '002', 'terno', 'plomo');
insert into BS_Prenda (idPrenda, idCategoria, descripcion, color) VALUES (21, '002', 'terno', 'negro');
insert into BS_Prenda (idPrenda, idCategoria, descripcion, color) VALUES (22, '002', 'terno', 'azul');
insert into BS_Prenda (idPrenda, idCategoria, descripcion, color) VALUES (23, '003', 'correa de cuero', 'negro');
insert into BS_Prenda (idPrenda, idCategoria, descripcion, color) VALUES (24, '003', 'correa de cuero', 'marron');
insert into BS_Prenda (idPrenda, idCategoria, descripcion, color) VALUES (25, '003', 'corbata', 'rojo');
insert into BS_Prenda (idPrenda, idCategoria, descripcion, color) VALUES (26, '003', 'corbata', 'negro');
insert into BS_Prenda (idPrenda, idCategoria, descripcion, color) VALUES (27, '003', 'corbata', 'lila');
insert into BS_Prenda (idPrenda, idCategoria, descripcion, color) VALUES (28, '004', 'buzo', 'blanco');
insert into BS_Prenda (idPrenda, idCategoria, descripcion, color) VALUES (29, '004', 'buzo', 'negro');
insert into BS_Prenda (idPrenda, idCategoria, descripcion, color) VALUES (30, '004', 'buzo', 'verde');
insert into BS_Prenda (idPrenda, idCategoria, descripcion, color) VALUES (31, '004', 'polo', 'anaranjado');
insert into BS_Prenda (idPrenda, idCategoria, descripcion, color) VALUES (32, '004', 'polo', 'negro');
insert into BS_Prenda (idPrenda, idCategoria, descripcion, color) VALUES (33, '004', 'polo', 'plomo');

insert into BS_Prenda (idPrenda, idCategoria, descripcion, color) VALUES (34, '005', 'Camiseta Manga Larga Cuello Redondo', 'Marino');
insert into BS_Prenda (idPrenda, idCategoria, descripcion, color) VALUES (35, '006', 'bufanda figuras geometricas', 'plateado');
insert into BS_Prenda (idPrenda, idCategoria, descripcion, color) VALUES (36, '007', 'cubrebata', 'celeste');
insert into BS_Prenda (idPrenda, idCategoria, descripcion, color) VALUES (37, '008', 'Bolsas Impermeable', 'azul');
insert into BS_Prenda (idPrenda, idCategoria, descripcion, color) VALUES (38, '009', 'toalla grande', 'blanco');
insert into BS_Prenda (idPrenda, idCategoria, descripcion, color) VALUES (39, '010', 'uniforme escolar falda', 'gris');
insert into BS_Prenda (idPrenda, idCategoria, descripcion, color) VALUES (40, '011', 'abrigo de alpaca', 'beige');
insert into BS_Prenda (idPrenda, idCategoria, descripcion, color) VALUES (41, '010', 'uniforme escolar pantalos', 'gris');
insert into BS_Prenda (idPrenda, idCategoria, descripcion, color) VALUES (42, '009', 'toalla de mano', 'blanco');
insert into BS_Prenda (idPrenda, idCategoria, descripcion, color) VALUES (43, '008', 'mochila', 'azul');
insert into BS_Prenda (idPrenda, idCategoria, descripcion, color) VALUES (44, '007', 'cubrebotas', 'celeste');
insert into BS_Prenda (idPrenda, idCategoria, descripcion, color) VALUES (45, '006', 'cinturos con mo�o ', 'plateado');
insert into BS_Prenda (idPrenda, idCategoria, descripcion, color) VALUES (46, '005', 'Camiseta Manga Corta Cuello V', 'blanco');
insert into BS_Prenda (idPrenda, idCategoria, descripcion, color) VALUES (47, '006', 'sombrero copa', 'negro');
insert into BS_Prenda (idPrenda, idCategoria, descripcion, color) VALUES (48, '007', 'polainas', 'celeste');
insert into BS_Prenda (idPrenda, idCategoria, descripcion, color) VALUES (49, '008', 'morral', 'azul');
insert into BS_Prenda (idPrenda, idCategoria, descripcion, color) VALUES (50, '009', 'toalla mediana', 'blanco');
insert into BS_Prenda (idPrenda, idCategoria, descripcion, color) VALUES (51, '010', 'uniforme escolar camisa', 'blanco');
insert into BS_Prenda (idPrenda, idCategoria, descripcion, color) VALUES (52, '010', 'uniforme escolar blusa', 'blanco');
insert into BS_Prenda (idPrenda, idCategoria, descripcion, color) VALUES (53, '010', 'uniforme escolar chompa', 'gris');
insert into BS_Prenda (idPrenda, idCategoria, descripcion, color) VALUES (54, '010', 'Polos de gimnasia', 'blanco');
insert into BS_Prenda (idPrenda, idCategoria, descripcion, color) VALUES (55, '010', 'Medias deportivas', 'blanco');
insert into BS_Prenda (idPrenda, idCategoria, descripcion, color) VALUES (56, '010', 'Mandil de laboratorio', 'blanco');

insert into bs_matriz_talla (idmatriz, idPrenda, talla, precio_venta ) VALUES (58,54, 'L', 30.00);
insert into bs_matriz_talla (idmatriz, idPrenda, talla, precio_venta ) VALUES (59,54, 'S', 30.00);
insert into bs_matriz_talla (idmatriz, idPrenda, talla, precio_venta ) VALUES (60,54, 'M', 30.00);

insert into bs_matriz_talla (idmatriz, idPrenda, talla, precio_venta ) VALUES (61,55, 'L', 7.50);
insert into bs_matriz_talla (idmatriz, idPrenda, talla, precio_venta ) VALUES (62,55, 'XS', 7.50);
insert into bs_matriz_talla (idmatriz, idPrenda, talla, precio_venta ) VALUES (63,55, 'M', 7.50);

insert into bs_matriz_talla (idmatriz, idPrenda, talla, precio_venta ) VALUES (64,56, 'L', 37.50);
insert into bs_matriz_talla (idmatriz, idPrenda, talla, precio_venta ) VALUES (65,56, 'XL', 37.50);
insert into bs_matriz_talla (idmatriz, idPrenda, talla, precio_venta ) VALUES (66,56, 'M', 37.50);


insert into bs_matriz_talla (idmatriz, idPrenda, talla, precio_venta ) VALUES (1,53, 'XS', 31.50);
insert into bs_matriz_talla (idmatriz, idPrenda, talla, precio_venta ) VALUES (2,53, 'S', 31.50);
insert into bs_matriz_talla (idmatriz, idPrenda, talla, precio_venta ) VALUES (3,53, 'M', 31.50);
insert into bs_matriz_talla (idmatriz, idPrenda, talla, precio_venta ) VALUES (4,53, 'L', 41.50);
insert into bs_matriz_talla (idmatriz, idPrenda, talla, precio_venta ) VALUES (5,53, 'XL', 41.50);
insert into bs_matriz_talla (idmatriz, idPrenda, talla, precio_venta ) VALUES (6,53, 'XXL', 51.50);
insert into bs_matriz_talla (idmatriz, idPrenda, talla, precio_venta ) VALUES (7,52, 'XS', 31.50);
insert into bs_matriz_talla (idmatriz, idPrenda, talla, precio_venta ) VALUES (8,52, 'S', 31.50);
insert into bs_matriz_talla (idmatriz, idPrenda, talla, precio_venta ) VALUES (9,52, 'M', 31.50);
insert into bs_matriz_talla (idmatriz, idPrenda, talla, precio_venta ) VALUES (10,52, 'L', 41.50);
insert into bs_matriz_talla (idmatriz, idPrenda, talla, precio_venta ) VALUES (11,52, 'XL', 41.50);
insert into bs_matriz_talla (idmatriz, idPrenda, talla, precio_venta ) VALUES (12,52, 'XXL', 51.50);
insert into bs_matriz_talla (idmatriz, idPrenda, talla, precio_venta ) VALUES (13,51, 'XS', 31.50);
insert into bs_matriz_talla (idmatriz, idPrenda, talla, precio_venta ) VALUES (14,51, 'S', 31.50);
insert into bs_matriz_talla (idmatriz, idPrenda, talla, precio_venta ) VALUES (15,51, 'M', 31.50);
insert into bs_matriz_talla (idmatriz, idPrenda, talla, precio_venta ) VALUES (16,51, 'L', 41.50);
insert into bs_matriz_talla (idmatriz, idPrenda, talla, precio_venta ) VALUES (17,51, 'XL', 41.50);
insert into bs_matriz_talla (idmatriz, idPrenda, talla, precio_venta ) VALUES (18,51, 'XXL', 51.50);
insert into bs_matriz_talla (idmatriz, idPrenda, talla, precio_venta ) VALUES (19,41, 'XS', 39.50);
insert into bs_matriz_talla (idmatriz, idPrenda, talla, precio_venta ) VALUES (20,41, 'S', 39.50);
insert into bs_matriz_talla (idmatriz, idPrenda, talla, precio_venta ) VALUES (21,41, 'M', 39.50);
insert into bs_matriz_talla (idmatriz, idPrenda, talla, precio_venta ) VALUES (22,41, 'L', 49.50);
insert into bs_matriz_talla (idmatriz, idPrenda, talla, precio_venta ) VALUES (23,41, 'XL', 49.50);
insert into bs_matriz_talla (idmatriz, idPrenda, talla, precio_venta ) VALUES (24,41, 'XXL', 59.50);
insert into bs_matriz_talla (idmatriz, idPrenda, talla, precio_venta ) VALUES (25,39, 'XS', 39.50);
insert into bs_matriz_talla (idmatriz, idPrenda, talla, precio_venta ) VALUES (26,39, 'S', 39.50);
insert into bs_matriz_talla (idmatriz, idPrenda, talla, precio_venta ) VALUES (27,39, 'M', 39.50);
insert into bs_matriz_talla (idmatriz, idPrenda, talla, precio_venta ) VALUES (28,39, 'L', 49.50);
insert into bs_matriz_talla (idmatriz, idPrenda, talla, precio_venta ) VALUES (29,39, 'XL', 49.50);
insert into bs_matriz_talla (idmatriz, idPrenda, talla, precio_venta ) VALUES (30,39, 'XXL', 59.50);
insert into bs_matriz_talla (idmatriz, idPrenda, talla, precio_venta ) VALUES (31,17, 'XS', 55.50);
insert into bs_matriz_talla (idmatriz, idPrenda, talla, precio_venta ) VALUES (32,17, 'S', 55.50);
insert into bs_matriz_talla (idmatriz, idPrenda, talla, precio_venta ) VALUES (33,17, 'M', 55.50);
insert into bs_matriz_talla (idmatriz, idPrenda, talla, precio_venta ) VALUES (34,17, 'L', 59.50);
insert into bs_matriz_talla (idmatriz, idPrenda, talla, precio_venta ) VALUES (35,17, 'XL', 59.50);
insert into bs_matriz_talla (idmatriz, idPrenda, talla, precio_venta ) VALUES (36,17, 'XXL', 64.50);
insert into bs_matriz_talla (idmatriz, idPrenda, talla, precio_venta ) VALUES (37,17, 'XXXL', 69.50);
insert into bs_matriz_talla (idmatriz, idPrenda, talla, precio_venta ) VALUES (38,18, 'XS', 55.50);
insert into bs_matriz_talla (idmatriz, idPrenda, talla, precio_venta ) VALUES (39,18, 'S', 55.50);
insert into bs_matriz_talla (idmatriz, idPrenda, talla, precio_venta ) VALUES (40,18, 'M', 55.50);
insert into bs_matriz_talla (idmatriz, idPrenda, talla, precio_venta ) VALUES (41,18, 'L', 59.50);
insert into bs_matriz_talla (idmatriz, idPrenda, talla, precio_venta ) VALUES (42,18, 'XL', 59.50);
insert into bs_matriz_talla (idmatriz, idPrenda, talla, precio_venta ) VALUES (43,18, 'XXL', 64.50);
insert into bs_matriz_talla (idmatriz, idPrenda, talla, precio_venta ) VALUES (44,18, 'XXXL', 69.50);
insert into bs_matriz_talla (idmatriz, idPrenda, talla, precio_venta ) VALUES (45,19, 'XS', 55.50);
insert into bs_matriz_talla (idmatriz, idPrenda, talla, precio_venta ) VALUES (46,19, 'S', 55.50);
insert into bs_matriz_talla (idmatriz, idPrenda, talla, precio_venta ) VALUES (47,19, 'M', 55.50);
insert into bs_matriz_talla (idmatriz, idPrenda, talla, precio_venta ) VALUES (48,19, 'L', 59.50);
insert into bs_matriz_talla (idmatriz, idPrenda, talla, precio_venta ) VALUES (49,19, 'XL', 59.50);
insert into bs_matriz_talla (idmatriz, idPrenda, talla, precio_venta ) VALUES (50,19, 'XXL', 64.50);
insert into bs_matriz_talla (idmatriz, idPrenda, talla, precio_venta ) VALUES (51,19, 'XXXL', 69.50);
insert into bs_matriz_talla (idmatriz, idPrenda, talla, precio_venta ) VALUES (52,23, 'S', 55.50);
insert into bs_matriz_talla (idmatriz, idPrenda, talla, precio_venta ) VALUES (53,24, 'M', 55.50);
insert into bs_matriz_talla (idmatriz, idPrenda, talla, precio_venta ) VALUES (54,23, 'L', 59.50);
insert into bs_matriz_talla (idmatriz, idPrenda, talla, precio_venta ) VALUES (55,24, 'XL', 59.50);
insert into bs_matriz_talla (idmatriz, idPrenda, talla, precio_venta ) VALUES (56,24, 'XXL', 64.50);
insert into bs_matriz_talla (idmatriz, idPrenda, talla, precio_venta ) VALUES (57,23, 'XXXL', 69.50);

insert into bs_tienda (idtienda, fechaapertura) VALUES (1,NULL);
insert into bs_tienda (idtienda, fechaapertura) VALUES (2,NULL);
insert into bs_tienda (idtienda, fechaapertura) VALUES (3,NULL);
insert into bs_tienda (idtienda, fechaapertura) VALUES (4,NULL);
insert into bs_tienda (idtienda, fechaapertura) VALUES (5,NULL);


insert into bs_inventario (idinventario, idtienda , idmatriz, idPrenda, stock) VALUES (1,1,57,23,6);
insert into bs_inventario (idinventario, idtienda , idmatriz, idPrenda, stock) VALUES (58,2,1,53, 1);
insert into bs_inventario (idinventario, idtienda , idmatriz, idPrenda, stock) VALUES (57,3,2,53, 1);
insert into bs_inventario (idinventario, idtienda , idmatriz, idPrenda, stock) VALUES (56,4,3,53, 1);
insert into bs_inventario (idinventario, idtienda , idmatriz, idPrenda, stock) VALUES (55,5,4,53, 2);
insert into bs_inventario (idinventario, idtienda , idmatriz, idPrenda, stock) VALUES (54,1,5,53, 3);
insert into bs_inventario (idinventario, idtienda , idmatriz, idPrenda, stock) VALUES (53,4,6,53, 5);
insert into bs_inventario (idinventario, idtienda , idmatriz, idPrenda, stock) VALUES (52,3,7,52, 1);
insert into bs_inventario (idinventario, idtienda , idmatriz, idPrenda, stock) VALUES (51,2,8,52, 2);
insert into bs_inventario (idinventario, idtienda , idmatriz, idPrenda, stock) VALUES (50,1,9,52, 3);
insert into bs_inventario (idinventario, idtienda , idmatriz, idPrenda, stock) VALUES (49,3,10,52,4);
insert into bs_inventario (idinventario, idtienda , idmatriz, idPrenda, stock) VALUES (48,4,11,52, 3);
insert into bs_inventario (idinventario, idtienda , idmatriz, idPrenda, stock) VALUES (47,5,12,52, 50);
insert into bs_inventario (idinventario, idtienda , idmatriz, idPrenda, stock) VALUES (46,1,13,51, 50);
insert into bs_inventario (idinventario, idtienda , idmatriz, idPrenda, stock) VALUES (45,4,14,51, 50);
insert into bs_inventario (idinventario, idtienda , idmatriz, idPrenda, stock) VALUES (43,2,16,51, 15);
insert into bs_inventario (idinventario, idtienda , idmatriz, idPrenda, stock) VALUES (42,3,17,51, 41);
insert into bs_inventario (idinventario, idtienda , idmatriz, idPrenda, stock) VALUES (41,4,18,51, 51);
insert into bs_inventario (idinventario, idtienda , idmatriz, idPrenda, stock) VALUES (40,5,19,41, 39);
insert into bs_inventario (idinventario, idtienda , idmatriz, idPrenda, stock) VALUES (39,1,20,41, 39);
insert into bs_inventario (idinventario, idtienda , idmatriz, idPrenda, stock) VALUES (38,4,21,41, 39);
insert into bs_inventario (idinventario, idtienda , idmatriz, idPrenda, stock) VALUES (37,3,22,41, 50);
insert into bs_inventario (idinventario, idtienda , idmatriz, idPrenda, stock) VALUES (36,2,23,41, 49);
insert into bs_inventario (idinventario, idtienda , idmatriz, idPrenda, stock) VALUES (35,1,24,41, 59);
insert into bs_inventario (idinventario, idtienda , idmatriz, idPrenda, stock) VALUES (34,2,25,39, 39);
insert into bs_inventario (idinventario, idtienda , idmatriz, idPrenda, stock) VALUES (33,3,26,39, 50);
insert into bs_inventario (idinventario, idtienda , idmatriz, idPrenda, stock) VALUES (32,4,27,39, 39);
insert into bs_inventario (idinventario, idtienda , idmatriz, idPrenda, stock) VALUES (31,5,28,39, 49);
insert into bs_inventario (idinventario, idtienda , idmatriz, idPrenda, stock) VALUES (30,5,29,39, 50);
insert into bs_inventario (idinventario, idtienda , idmatriz, idPrenda, stock) VALUES (29,4,30,39, 10);
insert into bs_inventario (idinventario, idtienda , idmatriz, idPrenda, stock) VALUES (28,3,31,17, 20);
insert into bs_inventario (idinventario, idtienda , idmatriz, idPrenda, stock) VALUES (27,2,32,17, 30);
insert into bs_inventario (idinventario, idtienda , idmatriz, idPrenda, stock) VALUES (26,1,33,17, 40);
insert into bs_inventario (idinventario, idtienda , idmatriz, idPrenda, stock) VALUES (25,5,34,17, 50);
insert into bs_inventario (idinventario, idtienda , idmatriz, idPrenda, stock) VALUES (24,4,35,17, 20);
insert into bs_inventario (idinventario, idtienda , idmatriz, idPrenda, stock) VALUES (23,3,36,17, 50);
insert into bs_inventario (idinventario, idtienda , idmatriz, idPrenda, stock) VALUES (22,2,37,17, 9);
insert into bs_inventario (idinventario, idtienda , idmatriz, idPrenda, stock) VALUES (21,1,38,18, 55);
insert into bs_inventario (idinventario, idtienda , idmatriz, idPrenda, stock) VALUES (20,5,39,18, 55);
insert into bs_inventario (idinventario, idtienda , idmatriz, idPrenda, stock) VALUES (19,4,40,18, 5);
insert into bs_inventario (idinventario, idtienda , idmatriz, idPrenda, stock) VALUES (19,1,40,18, 19);
insert into bs_inventario (idinventario, idtienda , idmatriz, idPrenda, stock) VALUES (19,2,40,18, 1);
insert into bs_inventario (idinventario, idtienda , idmatriz, idPrenda, stock) VALUES (19,3,40,18, 8);
insert into bs_inventario (idinventario, idtienda , idmatriz, idPrenda, stock) VALUES (19,5,40,18, 2);
insert into bs_inventario (idinventario, idtienda , idmatriz, idPrenda, stock) VALUES (18,3,41,18, 95);
insert into bs_inventario (idinventario, idtienda , idmatriz, idPrenda, stock) VALUES (17,1,42,18, 59);
insert into bs_inventario (idinventario, idtienda , idmatriz, idPrenda, stock) VALUES (16,2,43,18, 64);
insert into bs_inventario (idinventario, idtienda , idmatriz, idPrenda, stock) VALUES (15,5,44,18, 6);
insert into bs_inventario (idinventario, idtienda , idmatriz, idPrenda, stock) VALUES (14,4,45,19, 55);
insert into bs_inventario (idinventario, idtienda , idmatriz, idPrenda, stock) VALUES (13,3,46,19, 5);
insert into bs_inventario (idinventario, idtienda , idmatriz, idPrenda, stock) VALUES (12,2,47,19, 50);
insert into bs_inventario (idinventario, idtienda , idmatriz, idPrenda, stock) VALUES (11,1,48,19, 9);
insert into bs_inventario (idinventario, idtienda , idmatriz, idPrenda, stock) VALUES (10,5,49,19, 95);
insert into bs_inventario (idinventario, idtienda , idmatriz, idPrenda, stock) VALUES (9,4,50,19, 65);
insert into bs_inventario (idinventario, idtienda , idmatriz, idPrenda, stock) VALUES (8,2,51,19, 60);
insert into bs_inventario (idinventario, idtienda , idmatriz, idPrenda, stock) VALUES (7,2,52,23, 55);
insert into bs_inventario (idinventario, idtienda , idmatriz, idPrenda, stock) VALUES (6,1,53,24, 50);
insert into bs_inventario (idinventario, idtienda , idmatriz, idPrenda, stock) VALUES (5,5,54,23, 5);
insert into bs_inventario (idinventario, idtienda , idmatriz, idPrenda, stock) VALUES (4,4,55,24, 59);
insert into bs_inventario (idinventario, idtienda , idmatriz, idPrenda, stock) VALUES (3,3,56,24, 64);
insert into bs_inventario (idinventario, idtienda , idmatriz, idPrenda, stock) VALUES (2,2,57,23, 50);

insert into bs_orden_fabricacion (idorden, fecha_creacion, idempleado, fecha_entrega_estimada, fecha_entrega_real, costo_total) 
values (1001, (sysdate-60), 'EMP005', (sysdate + 30), null, 0);

insert into bs_detalle_orden (idorden, idguiapreventa, idinventario, idtienda) 
values (1001, 2001, 57, 3);
insert into bs_detalle_orden (idorden, idguiapreventa, idinventario, idtienda) 
values (1001, 2001, 42, 3);
insert into bs_detalle_orden (idorden, idguiapreventa, idinventario, idtienda) 
values (1001, 2001, 37, 3);

insert into bs_orden_fabricacion (idorden, fecha_creacion, idempleado, fecha_entrega_estimada, fecha_entrega_real, costo_total) 
values (1002, (sysdate-50), 'EMP003', (sysdate + 4), null, 0);

insert into bs_detalle_orden (idorden, idguiapreventa, idinventario, idtienda) 
values (1002, 2002, 19, 1);
insert into bs_detalle_orden (idorden, idguiapreventa, idinventario, idtienda) 
values (1002, 2002, 11, 1);
insert into bs_detalle_orden (idorden, idguiapreventa, idinventario, idtienda) 
values (1002, 2002, 6, 1);
insert into bs_detalle_orden (idorden, idguiapreventa, idinventario, idtienda) 
values (1002, 2002, 26, 1);

insert into bs_orden_fabricacion (idorden, fecha_creacion, idempleado, fecha_entrega_estimada, fecha_entrega_real, costo_total) 
values (1003, (sysdate-40), 'EMP002', (sysdate + 10), null, 0);

insert into bs_detalle_orden (idorden, idguiapreventa, idinventario, idtienda) 
values (1003, 2003, 14, 1);
insert into bs_detalle_orden (idorden, idguiapreventa, idinventario, idtienda) 
values (1003, 2003, 24, 1);

commit;