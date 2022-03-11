FROM debian:11-slim AS builder
RUN apt-get update \
    && apt-get install -y \
    libcurl4-openssl-dev \
    make \
    gcc
WORKDIR /app
COPY . .
RUN make

FROM debian:11-slim
RUN apt-get update \
    && apt-get install -y \
    libcurl4 \
    && rm -rf /var/lib/apt/lists/*
COPY --from=builder /app/get_rand_proxy /usr/local/bin/
CMD ["get_rand_proxy"]
