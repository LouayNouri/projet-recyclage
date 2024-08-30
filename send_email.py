# send_email.py
import smtplib
import sys
from email.mime.text import MIMEText

def send_email(receiver_email, new_password):
    sender_email = "hamzama446@gmail.com"
    sender_password = "aoxh gdtt rpnp mywo"
    smtp_server = "smtp.gmail.com"
    smtp_port = 587

    msg = MIMEText(f"Your new password is: {new_password}")
    msg['Subject'] = 'Password Reset'
    msg['From'] = sender_email
    msg['To'] = receiver_email

    try:
        server = smtplib.SMTP(smtp_server, smtp_port)
        server.starttls()
        server.login(sender_email, sender_password)
        server.sendmail(sender_email, receiver_email, msg.as_string())
        server.quit()
        print("Success")
    except Exception as e:
        print(f"Error: {e}")

if __name__ == "__main__":
    receiver_email = sys.argv[1]
    new_password = sys.argv[2]
    send_email(receiver_email, new_password)
