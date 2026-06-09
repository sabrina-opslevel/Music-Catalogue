#!/usr/bin/env python3
"""
Create 5 sets of nested files with 2 files each containing lorem of 2.
Skip testing as per instructions.
"""
import os

def create_nested_files():
    """Create 5 sets of nested files with 2 files each."""
    print("Creating 5 sets of nested files with 2 files each containing lorem of 2...")
    
    for i in range(1, 6):
        dir_name = f"set_{i}"
        os.makedirs(dir_name, exist_ok=True)
        
        # Create 2 files in each directory
        for j in range(1, 3):
            file_path = os.path.join(dir_name, f"file{j}.txt")
            with open(file_path, 'w') as f:
                f.write("Lorem ipsum\n")
    
    print("Done! Created 5 sets of nested files.")

def clean():
    """Clean up the nested file sets."""
    import shutil
    print("Cleaning up nested file sets...")
    
    for i in range(1, 6):
        dir_name = f"set_{i}"
        if os.path.exists(dir_name):
            shutil.rmtree(dir_name)
    
    print("Cleanup complete.")

def test():
    """Test function - skipped as per instructions."""
    print("Testing skipped as per instructions.")

if __name__ == "__main__":
    import sys
    
    if len(sys.argv) > 1:
        command = sys.argv[1]
        if command == "clean":
            clean()
        elif command == "test":
            test()
        else:
            print(f"Unknown command: {command}")
            print("Usage: python3 create_nested_files.py [clean|test]")
    else:
        create_nested_files()
