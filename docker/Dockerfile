FROM alpine:3.18 AS builder

RUN apk add --no-cache build-base pkgconfig zlib-ng-dev

WORKDIR /app
COPY . .

RUN make

FROM alpine:3.18

RUN apk add --no-cache zlib-ng

COPY --from=builder /app/libklib.so /usr/local/lib/
RUN ldconfig /usr/local/lib

WORKDIR /lib
