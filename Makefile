all: main.cpp
	@printf 'Creating executable file, please wait...\n'
	@g++ main.cpp -o Lab3
	@printf 'Success! Created file Lab3\n\n'
clean:
	@echo 'Cleaning up the mess...'
	@rm Lab3
	@echo 'Success!'
