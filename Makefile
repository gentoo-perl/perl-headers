# vim: set noet sw=8 ts=8:

root = $(shell pwd)

linuxheaders = asm/termios.h	\
		limits.h	\
		syscall.h	\
		sysexits.h	\
		syslog.h	\
		sys/ioctl.h	\
		sys/socket.h	\
		sys/time.h	\
		wait.h

patches = _h2ph_pre.ph		\
	sys/select.ph		\
	bits/socket.ph		\
	bits/sigcontext.ph

appenders: $(addprefix appended/,$(patches))

bin/%: specs/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(CPPFLAGS) $< -o $@

append/%.ph: bin/%
	@mkdir -p $(@D)
	$< > $@

appended/%.ph: append/%.ph h2ph
	@mkdir -p $(@D)
	perl utils/append.pl headers/$*.ph $< $@

h2ph:
	@mkdir -p headers
	-cd /usr/include ; h2ph -Q -a $(H2PHARGS) -d $(shell pwd)/headers $(linuxheaders)

clean:
	$(RM) -r bin/ append/ headers/ appended/
