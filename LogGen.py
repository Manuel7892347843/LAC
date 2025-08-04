import random
from datetime import datetime, timedelta

methods = ["GET", "POST", "PUT", "DELETE"]
paths = ["/home", "/api", "/img", "/user"]
statuses = ["200", "404", "500", "302"]

start_time = datetime(2025, 8, 3, 0, 0)

with open("server_logs.txt", "w") as f:
    for i in range(3000):
        time = start_time + timedelta(minutes=i)
        ip = f"192.168.1.{random.randint(1, 100)}"
        method = random.choice(methods)
        path = random.choice(paths) + f"/{i}"
        status = random.choice(statuses)
        size = random.randint(100, 20000)
        f.write(f"[{time}] {ip} {method} {path} \"{status}\" {size} B\n")