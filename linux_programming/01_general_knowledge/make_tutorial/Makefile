.PHONY: rule1 rule2 rule3



var := "var"

var1 = $(var)
var2 := $(var)
var3 ?= $(var)

var := "changed"

rule3:
	@echo "$(var1)"
	@echo "$(var2)"
	@echo "$(var3)"

rule2:
	echo "hi i am rule 2"

rule1: 
	@echo "hi i am rule 1"
