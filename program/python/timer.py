import winsound
import time
enter = int(input('how many time do you want to wait?'))
time.sleep(enter)
winsound.PlaySound('beep', winsound.SND_ASYNC)
