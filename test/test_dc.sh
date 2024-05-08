#!/bin/sh

function dc_stripdots_nl () {
	echo $1 | ../src/dc | tr '\n' ' ' | sed "s/\.0\+//g"
}

function dc_operations () {
	test_cmd="2.5 2.5 +p 10 5 -p 10 2 *p 50 25 /p"
	expected="5 5 20 2 "
	got=$(dc_stripdots_nl "$test_cmd")

	#echo "expected $expected"
	#echo "got $got"

	if [[ "$expected" == "$got" ]]; then
		echo "op ok"
	else
		echo "op not ok"
	fi
}

function dc_printing () {
	test_cmd="10 p P p 10 20 40 f"
	expected="10 10 stack empty 10 20 40 "
	got=$(dc_stripdots_nl "$test_cmd")

	#echo "expected $expected"
	#echo "got $got"

	if [[ "$expected" == "$got" ]]; then
		echo "prt ok"
	else
		echo "prt not ok"
	fi
}

function dc_stack_manipulation () {
	test_cmd="10 20 30 c p 10 d P P P"
	expected="stack empty 10 10 stack empty "
	got=$(dc_stripdots_nl "$test_cmd")

	#cho "expected $expected"
	#echo "got $got"

	if [[ "$expected" == "$got" ]]; then
		echo "sm ok"
	else
		echo "sm not ok"
	fi
}

function dc_registers () {
	test_cmd="10 p sa la p"
	expected="10 10 "
	got=$(dc_stripdots_nl "$test_cmd")

	#echo "expected $expected"
	#echo "got $got"

	if [[ "$expected" == "$got" ]]; then
		echo "reg ok"
	else
		echo "reg not ok"
	fi
}

dc_operations;
dc_printing;
dc_stack_manipulation;
dc_registers;