import mysql.connector
import psycopg2
import sqlite3

def connect_to_db(db_type, user, password, host, database):
    """
    Connect to a database of the specified type and return a cursor object.
    :param db_type: The type of database to connect to (mysql, postgres, or sqlite)
    :param user: The username to use when connecting to the database
    :param password: The password to use when connecting to the database
    :param host: The hostname or IP address of the database server
    :param database: The name of the database to connect to
    :return: A cursor object for executing queries on the database
    """
    cnx = None
    cursor = None
    if db_type == 'mysql':
        cnx = mysql.connector.connect(user=user, password=password, host=host, database=database)
        cursor = cnx.cursor()
    elif db_type == 'postgres':
        cnx = psycopg2.connect(user=user, password=password, host=host, database=database)
        cursor = cnx.cursor()
    elif db_type == 'sqlite':
        cnx = sqlite3.connect(database)
        cursor = cnx.cursor()
    else:
        print(f"Error: Unsupported database type {db_type}")
        return None, None
    return cnx, cursor

def choose_database():
    """
    Prompt the user to choose a database to connect to and return the connection details.
    :return: A tuple containing the database type, username, password, host, and database name
    """
    db_type = input("Choose a database to connect to (mysql, postgres, or sqlite): ")
    user = input("Enter your username: ")
    password = input("Enter your password: ")
    host = input("Enter the hostname or IP address of the database server: ")
    database = input("Enter the name of the database: ")
    return db_type, user, password, host, database

if __name__ == "__main__":
    db_type, user, password, host, database = choose_database()
    cnx, cursor = connect_to_db(db_type, user, password, host, database)
    if cursor:
        cursor.execute("SELECT * FROM your_table")
        results = cursor.fetchall()
        for row in results:
            print(row)
        cursor.close()
        cnx.close()
