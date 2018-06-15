FROM alpine:3.3

COPY ./sleep.sh /tmp/
RUN chmod +x /tmp/sleep.sh

ENTRYPOINT ["/tmp/sleep.sh"]
