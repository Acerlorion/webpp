# webpp

A proof of concept of Emscripten working with OpenGL and C++.

YOU NEED THE [EMSCRIPTEN SDK](https://emscripten.org/docs/getting_started/downloads.html) IN ORDER TO BUILD THE PROJECT.

## Usage

I did a very little command line interpreter in Bash to make building and starting the project easier.

```
./webppcli build
```

After this command, you should have a new ```build``` folder. 
If there is a problem, please create and issue.

```
./webppcli start
```

This will start a local web server with the port ```8000```.
You can now open you web browser and go to ```http://localhost:8000/webpp.html``` to see the project running.

## License

This project is licensed under [MIT](https://github.com/acerlorion/webpp/-/blob/master/LICENSE).

## Contributor

[Paul Beauduc](https://github.com/acerlorion)
