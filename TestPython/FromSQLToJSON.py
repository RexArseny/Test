import MySQLdb
import json
import datetime

print('Введите пароль')
pas = input()
db = MySQLdb.connect(user="root", passwd=pas, db="mtuci", charset="utf8")
cur = db.cursor()
cur.execute('select *from students')
data = [dict((cur.description[i][0], value if (not isinstance(value, datetime.date)) else str(value)) for i, value in enumerate(row)) for row in cur.fetchall()]
cur.close()
file = open('result.json', 'w')
json.dump(data, file, ensure_ascii=False)
file.close()
