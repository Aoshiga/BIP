PACK?=platoon
SYS?=SYS()

V?=0.0.2
N?=10
TOOLS=../tools
BIP=${TOOLS}/bipc/bin/bipc.sh
DR_PATH=${TOOLS}/drbip
BIPEXEC?=./exec.sh
VER?=
TPREFIX?=
TFILE=${TPREFIX}${PACK}-$N-$(shell date +"%s")

VIEWER?=show


.PHONY: default setup execute limit genbip gendrbip clean all trace viewtraces model info gencode

default : info


gencode:
	make clean
	make setup
	make genbip
	make gendrbip
	@echo "--------"
	@echo "Code generated, use 'execute' or 'limit N=%n' to execute"
	@echo "--------"

setup:
	make clean
	mkdir -p output build

gentestmodel:
	(cd model && make)

genmodel:
	(cd model && make base && make benchparams)

cleanmodel:
	(cd model && make clean)

genbip:
	${BIP} -p ${PACK} -d "${SYS}" \
			-f 'ujf.verimag.bip.middleend.gluetranslator.GluetranslatorFilter!ujf.verimag.bip.middleend.xflattening.XflatteningFilter' \
			-I model \
		  --gencpp-output-dir output --gencpp-no-engine

gendrbip:
	${DR_PATH}/drbip model${PRE}/${PACK}${VER}.drbip output/Deploy model${PRE}
	${DR_PATH}/scripts/mktemplates ${PACK} output/Deploy
	cp -f model/*.cpp output/Deploy 2>/dev/null || true
	cp -f model/*.h output/Deploy  2>/dev/null || true
	cp -f model/*.hpp output/Deploy 2>/dev/null || true

execute:
	${BIPEXEC}

bench:
	${BIPEXEC} "--limit ${N}" "-DPERFMODE"

limit:
	${BIPEXEC} "--limit ${N}"

trace:
	${BIPEXEC} "--limit ${N}" | grep "<TRACE>" | tee ${PACK}.txt
	java -cp ${DR_PATH}/drbip-trace-${V}.jar ujf.verimag.drbip.trace.JSON ${PACK}.txt ${PACK}
	mv ${PACK}.txt last-raw.txt
	mv ${PACK}.json ${TFILE}.json

clean:
	rm -rf build output *.json

info:
	$(info "Read README to execute models")
