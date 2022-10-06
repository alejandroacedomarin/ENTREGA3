DROP DATABASE IF EXISTS Othello;
CREATE DATABASE Othello;

USE Othello;

CREATE TABLE Jugador(
    Username VARCHAR(10) NOT NULL,
    Password VARCHAR(10) NOT NULL,
    Nivel INTEGER,
    PRIMARY KEY (Username)
)ENGINE = InnoDB;

CREATE TABLE Partida(
    id VARCHAR(5) NOT NULL,
    FechaInicio DATE,
    FechaFinal DATE,
    Ganador VARCHAR(10),
    PRIMARY KEY (id)
)ENGINE = InnoDB;

CREATE TABLE Juego(
    idPartida VARCHAR(5),
    Username1 VARCHAR(10) NOT NULL,
    Username2 VARCHAR(10) NOT NULL,
    FOREIGN KEY (idPartida) REFERENCES Partida(id),
    FOREIGN KEY (Username1) REFERENCES Jugador(Username),
    FOREIGN KEY (Username2) REFERENCES Jugador(Username)

)ENGINE = InnoDB;

INSERT INTO Jugador VALUES ('Juan','1234',2);
INSERT INTO Jugador VALUES ('Maria','1234',3);
INSERT INTO Jugador VALUES ('Jose','1234',4);

INSERT INTO Partida VALUES ('asae','06/09/03','07/09/03','Juan');
INSERT INTO Partida VALUES ('asai','08/09/03','09/09/03','Maria');

INSERT INTO Juego VALUES ('asae','Juan','Maria');
INSERT INTO Juego VALUES ('asai','Jose','Maria');

