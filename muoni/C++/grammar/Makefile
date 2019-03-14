grammar:
	java -Xmx500M -cp "/usr/local/lib/antlr-4.7.1-complete.jar:${CLASSPATH}" org.antlr.v4.Tool -Dlanguage=Cpp -no-listener -visitor -o antlr4-runtime Muon.g4
	mv antlr4-runtime/*.h ../inc/Grammar
	mv antlr4-runtime/*.cpp ../src/Grammar
	touch ../CMakeLists.txt
	git add ../inc/Grammar/*
	git add ../src/Grammar/*

clean:
	rm antlr4-runtime/* ../inc/Grammar/* ../src/Grammar/*
