import mysql.connector
import psycopg2
import sqlite3
import redis

def connect_to_db(db_type, user=None, password=None, host=None, database=None, port=None):
    """
    Connect to a database of the specified type and return a cursor object.
    :param db_type: The type of database to connect to (mysql, postgres, sqlite or redis)
    :param user: The username to use when connecting to the database
    :param password: The password to use when connecting to the database
    :param host: The hostname or IP address of the database server
    :param database: The name of the database to connect to
    :param port: The port number of the redis server
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
    elif db_type == 'redis':
        cnx = redis.Redis(host=host, port=port)
    else:
        print(f"Error: Unsupported database type {db_type}")
        return None, None
    return cnx, cursor

def choose_database():
    """
    Prompt the user to choose a database to connect to and return the connection details.
    :return: A tuple containing the database type, username, password, host, database name and port (if redis)
    """
    db_type = input("Choose a database to connect to (mysql, postgres, sqlite or redis): ")
    if db_type == "redis":
        host = input("Enter the hostname or IP address of the Redis server: ")
        port = input("Enter the port number of the Redis server: ")
        return db_type, host, port
    else:
        user = input("Enter your username: ")
        password = input("Enter your password: ")
        host = input("Enter the hostname or IP address of the database server: ")
        database = input("Enter the name of the database: ")
        return db_type, user, password, host, database

if __name__ == "__main__":
    db_type, user, password, host, database, port = choose_database()
    cnx, cursor = connect_to_db(db_type, user, password, host, database, port)
    if cursor:
       
