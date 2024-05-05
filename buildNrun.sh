docker build -t cpp-container .
docker run -v "$(pwd)":/usr/src -it cpp-container sh