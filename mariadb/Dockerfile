FROM ubuntu:16.04

RUN apt-get update && apt-get install -y software-properties-common && \
   apt-key adv --recv-keys --keyserver hkp://keyserver.ubuntu.com:80 0xF1656F24C74CD1D8 && \
  add-apt-repository 'deb [arch=amd64,i386] http://mirror.lstn.net/mariadb/repo/10.2/ubuntu zesty main'

RUN apt-get update && \
    echo 'mysql-server mysql-server/root_password password vmturbo' | debconf-set-selections && \ 
    echo 'mysql-server mysql-server/root_password_again password vmturbo' | debconf-set-selections && \
   apt-get install -y mariadb-server


COPY ./sleep.sh /tmp/sleep.sh
RUN chmod +x /tmp/sleep.sh
EXPOSE 3306

ENTRYPOINT ["/tmp/sleep.sh"]

