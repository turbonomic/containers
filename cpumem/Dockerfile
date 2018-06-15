FROM alpine:3.3
#RUN apk add --update alpine-sdk
RUN apk add --no-cache build-base

ARG SOURCE_COMMIT
LABEL git-rev="$SOURCE_COMMIT"

RUN mkdir /var/xxx/
RUN chmod 777 /var/xxx


COPY ./src/nummem.c /var/xxx/
COPY ./src/mem.c /var/xxx/
COPY ./src/cpu.c /var/xxx/
COPY ./src/run.sh /var/xxx/

WORKDIR /var/xxx/ 
#RUN gcc nummem.c -o memnum
#RUN gcc mem.c -o mempercent
#
#RUN chmod +x memnum
#RUN chmod +x mempercent

RUN chmod +x run.sh

ENTRYPOINT ["./run.sh"]
