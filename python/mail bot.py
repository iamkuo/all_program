import smtplib
from email.mime.text import MIMEText
from email.header import Header
 
sender = 'ryan.spaceexplore@gmail.com'
receivers = 'rykuo1006@gmail.com'
message = MIMEText('Python 邮件发送测试...', 'plain', 'utf-8')
message['From'] = Header("ryan", 'utf-8')
message['To'] =  Header("ryan", 'utf-8')
 
subject = 'hihi'
message['Subject'] = Header(subject, 'utf-8')
smtp = smtplib.SMTP('smtp.gmail.com',587)
smtp.starttls()
smtp.login('ryan.spaceexplorer@gmail.com','ryan0911')
for i in range(10):
    smtp.sendmail(sender, receivers, message.as_string())
    print("邮件发送成功")
