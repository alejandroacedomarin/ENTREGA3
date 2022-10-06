//programa en C para consultar los datos de la base de datos
//Incluir esta libreria para poder hacer las llamadas en shiva2.upc.es
//#include <my_global.h>
#include <mysql.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int main(int argc, char **argv)
{
	MYSQL *conn;
	int err;
	// Estructura especial para almacenar resultados de consultas 
	MYSQL_RES *resultado;
	MYSQL_ROW row;
	int Nivel;
	char Username[10];
	char consulta [80];
	//Creamos una conexion al servidor MYSQL 
	conn = mysql_init(NULL);
	if (conn==NULL) {
		printf ("Error al crear la conexionn: %u %s\n", 
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	//inicializar la conexion
	conn = mysql_real_connect (conn, "localhost","user", "pass", "Othello",0, NULL, 0);
	if (conn==NULL) {
		printf ("Error al inicializar la conexione: %u %s\n", 
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	err=mysql_query (conn, "SELECT * FROM Jugador");
	if (err!=0) {
		printf ("Error al consultar datos de la base %u %s\n",
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	
	resultado = mysql_store_result (conn);
	
	row = mysql_fetch_row (resultado);
	
	if (row == NULL)
		printf ("No se han obtenido datos en la consulta\n");
	else
		while (row !=NULL) {
			
			Nivel = atoi (row[2]);
			
			printf ("Username: %s, Password: %s, Nivel: %d\n", row[0], row[1], Nivel);
			
			row = mysql_fetch_row (resultado);
	}
	//Dame el nivel de la persona pasada por parametro.
	
	printf ("Dame el username de la persona que quieres saber el nivel\n"); 
	scanf ("%s", Username);
	// construimos la consulta SQL
	strcpy (consulta,"SELECT Nivel FROM Jugador WHERE Username = '"); 
	strcat (consulta, Username);
	strcat (consulta,"'");
	// hacemos la consulta 
	err=mysql_query (conn, consulta); 
	if (err!=0) {
		printf ("Error al consultar datos de la base %u %s\n",
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	//recogemos el resultado de la consulta 
	resultado = mysql_store_result (conn); 
	row = mysql_fetch_row (resultado);
	if (row == NULL)
		printf ("No se han obtenido datos en la consulta\n");
	else
		// El resultado debe ser una matriz con una sola fila
		// y una columna que contiene el nivel
		printf ("Nivel de la persona: %d\n", atoi(row[0]) );
	// cerrar la conexion con el servidor MYSQL 
		mysql_close (conn);
		exit(0);
}
