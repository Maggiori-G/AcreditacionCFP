CREATE DATABASE Transportista
USE Transportista

CREATE TABLE Ciudades
(Id_Ciudades INT NOT NULL PRIMARY KEY IDENTITY, 
 Nombre VARCHAR(50) NOT NULL) 

CREATE TABLE Camiones
(Matricula INT NOT NULL PRIMARY KEY, 
 Marca VARCHAR(30) NOT NULL, 
 Modelo VARCHAR(30) NOT NULL, 
 Potencia VARCHAR(30) NOT NULL, 
 Tipo VARCHAR(50) NOT NULL)

CREATE TABLE Camioneros
(Id_Camioneros INT NOT NULL PRIMARY KEY IDENTITY,
 Nombre VARCHAR(40) NOT NULL,
 Direccion VARCHAR(40) NOT NULL,
 Telefono VARCHAR(40) NOT NULL,
 Sueldo INT NOT NULL)

CREATE TABLE Paquete
(Id_Paquete INT NOT NULL PRIMARY KEY IDENTITY,
 Descripcion VARCHAR(50) NOT NULL,
 Destinatario VARCHAR(50) NOT NULL,
 Direccion VARCHAR(50) NOT NULL,
 Id_Camioneros INT NOT NULL FOREIGN KEY REFERENCES Camioneros(Id_Camioneros),
 Id_Ciudades INT NOT NULL FOREIGN KEY REFERENCES Ciudades(Id_Ciudades))

CREATE TABLE Detalle_De_Paquetes
(Id_DetalleDePaquetes INT NOT NULL PRIMARY KEY IDENTITY,
 Id_Camioneros INT NOT NULL FOREIGN KEY REFERENCES Camioneros(Id_Camioneros),
 Matricula INT NOT NULL FOREIGN KEY REFERENCES Camiones(Matricula))

 INSERT INTO Ciudades VALUES('Mendoza')
 INSERT INTO Ciudades VALUES('Misiones')
 INSERT INTO Ciudades VALUES('Salta')

 INSERT INTO Camiones VALUES(8000,'Scania','K410','600CV','24 Ruedas')
 INSERT INTO Camiones VALUES(8500,'Fiat','650E-18','500CV','18 Ruedas')
 INSERT INTO Camiones VALUES(8900,'Iveco','Eurocargo','550CV','12 Ruedas')

 INSERT INTO Camioneros VALUES('Dominguez','Calle Falsa 123','11-5220-6650', 150000)
 INSERT INTO Camioneros VALUES('Martinez','Calle Falsa 456','11-5731-9086', 180000)
 INSERT INTO Camioneros VALUES('Dominguez','Calle Falsa 789','15-8541-6713', 230000)

 INSERT INTO Paquete VALUES('Envio de mercado libre','Juanito','2675 Prairieview Place',1,2)
 INSERT INTO Paquete VALUES('Envio de mercado libre','Pepito','2719 Myrtle Drive',1,2)

 INSERT INTO Paquete VALUES('Envio de mercado libre','Gonzalito','5821 Forest Dale Road',3,1)
 INSERT INTO Paquete VALUES('Envio de mercado libre','Albertito','8 Shoshone Lane',3,1)

 INSERT INTO Paquete VALUES('Envio de mercado libre','Albertito Perez','56 Pearson Alley',3,3)
 INSERT INTO Paquete VALUES('Envio de mercado libre','Josesito Blanco','0812 Dryden Trail',3,3)
 INSERT INTO Paquete VALUES('Envio de mercado libre','Amanda Espinoza','27 Calypso Avenue',3,3)
 INSERT INTO Paquete VALUES('Envio de mercado libre','Berta Del Valle','33 Manitowish Street',3,3)
 INSERT INTO Paquete VALUES('Envio de mercado libre','Gonzalo Itturia','8274 Esker Way',3,3)
 INSERT INTO Paquete VALUES('Envio de mercado libre','Zoe Gonzalez','92 Sunfield Center',3,3)
 INSERT INTO Paquete VALUES('Envio de mercado libre','Walter Amado','337 Bartelt Center',3,3)
 INSERT INTO Paquete VALUES('Envio de mercado libre','Lautaro Esposito','920 Rigney Lane',3,3)
 INSERT INTO Paquete VALUES('Envio de mercado libre','Gianni Maggiori','3432 Red Cloud Point',3,3)
 INSERT INTO Paquete VALUES('Envio de mercado libre','Mayra Maestu','2740 Washington Hill',3,3)
 INSERT INTO Paquete VALUES('Envio de mercado libre','Gladys Morales','1171 Forest Run Road',3,3)
 INSERT INTO Paquete VALUES('Envio de mercado libre','Ruth Del Caño','640 Esker Road',3,3)
 INSERT INTO Paquete VALUES('Envio de mercado libre','Jason Maestu','6239 Hintze Center',3,3)
 INSERT INTO Paquete VALUES('Envio de mercado libre','Darth Vader','918 Burrows Circle',3,3)
 INSERT INTO Paquete VALUES('Envio de mercado libre','Pablo Maggiori','31 Division Way',3,3)

 SELECT * FROM Camiones

 UPDATE Camiones SET Matricula=8795 WHERE Marca='Scania'
 
 SELECT SUM(Sueldo) AS Total_Sueldo FROM Camioneros 

 SELECT * FROM Paquete

 SELECT * FROM Paquete WHERE Id_Ciudades=3

 SELECT * FROM Paquete WHERE Id_Ciudades=3 ORDER BY Destinatario

 DELETE FROM Paquete WHERE Id_Paquete = 4
 
 /*
 La unica forma de borrar especificamente un registro es sabiendo o teniendo el identificador, sino en el argumento
 del where hay que especificar la logica que borra usando top y eso trae todos los registros que se pongan en la logica con el top
 pero no pueden ser registros especificos en el top.
 El punto I no se puede hacer a menos que se ordene con un count lo cual seria lo mismo que hacer un select * from paquetes
 ya que el id de paquete es identity (o deberia serlo al menos) o mismo invertir lo anterior (haciendo un ordenamiento
 de id de menor a mayor) o hacer algun ordenamiento alfabetico por destinatario o algun otro campo alfabetico pero la consigna
 no tiene sentido, decidi que haga un select por destinatario para utilizar order by y al menos tener una lista ordenada
 por algun campo alfabetico que tenga algun sentido, tambien agregue paquetes enviados a Salta para poder armar algo que sea 
 lo mas acercado a lo que la consigna pide
 */

 


 