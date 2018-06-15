FROM ubuntu:17.04 

RUN apt-get update && apt-get install curl net-tools iputils-ping -y
RUN apt-get install vim -y

COPY ./sleep.sh /tmp/
COPY ./call.sh /tmp/
RUN chmod +x /tmp/sleep.sh
RUN chmod +x /tmp/call.sh

ENTRYPOINT ["/tmp/sleep.sh"]
