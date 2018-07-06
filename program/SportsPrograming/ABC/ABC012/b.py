N = input()
hour = N / 3600
minute = (N % 3600) / 60
sec = (N % 3600) % 60
print "{0:02d}".format(hour)+':'+"{0:02d}".format(minute)+':'+"{0:02d}".format(sec)
