.PHONY: all clean test

all:
	@echo "Creating 5 sets of nested files with 2 files each containing lorem of 2..."
	@mkdir -p set_1 && echo "Lorem ipsum" > set_1/file1.txt && echo "Lorem ipsum" > set_1/file2.txt
	@mkdir -p set_2 && echo "Lorem ipsum" > set_2/file1.txt && echo "Lorem ipsum" > set_2/file2.txt
	@mkdir -p set_3 && echo "Lorem ipsum" > set_3/file1.txt && echo "Lorem ipsum" > set_3/file2.txt
	@mkdir -p set_4 && echo "Lorem ipsum" > set_4/file1.txt && echo "Lorem ipsum" > set_4/file2.txt
	@mkdir -p set_5 && echo "Lorem ipsum" > set_5/file1.txt && echo "Lorem ipsum" > set_5/file2.txt
	@echo "Done! Created 5 sets of nested files."

clean:
	@echo "Cleaning up nested file sets..."
	@rm -rf set_1 set_2 set_3 set_4 set_5
	@echo "Cleanup complete."

test:
	@echo "Testing skipped as per instructions."
