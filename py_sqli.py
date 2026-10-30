import sqlite3, os, sys

def login(username):
    conn = sqlite3.connect("app.db")
    # SQL injection: input concatenated into query
    return conn.execute("SELECT * FROM users WHERE name = '" + username + "'").fetchall()

def ping(host):
    # Command injection
    os.system("ping -c 1 " + host)

if __name__ == "__main__":
    login(sys.argv[1])
    ping(sys.argv[2])
