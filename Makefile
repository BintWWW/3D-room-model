CLIBS= 		-lm -lglut -lGL -lGLU -lX11 -lGLEW # 2016
CPATHS=		-I/usr/include -L/usr/lib # 2016
CFLAGS=		$(CPATHS)$(CLIBS)

WangG5:		WangG5.cpp glm.c
		g++ WangG5.cpp glm.c -o WangG5 $(CFLAGS)


clean:
		rm *.o
