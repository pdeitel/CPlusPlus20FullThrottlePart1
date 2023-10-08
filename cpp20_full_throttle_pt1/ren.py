import os
import fileinput
import sys
import shutil

def rename_project(old_name, new_name):
    # Get the current working directory
    current_directory = os.getcwd()

    # Check if the old project name exists in the current directory
    project_path = os.path.join(current_directory, old_name)
    if not os.path.exists(project_path):
        print(f"Project folder with the name '{old_name}' does not exist in the current directory.")
        return

    # Create the new project path by replacing the old name with the new name
    new_path = os.path.join(current_directory, new_name)

    # Check if the new project path already exists
    if os.path.exists(new_path):
        print(f"Project folder with the name '{new_name}' already exists in the current directory.")
        return

    try:
        # Rename the project folder
        shutil.move(project_path, new_path)
        print(f"Project folder '{old_name}' renamed to '{new_name}'.")

        # Iterate over files in the new project path and its subdirectories
        for root, dirs, files in os.walk(new_path):
            for file in files:
                file_path = os.path.join(root, file)
                new_file_name = file.replace(old_name, new_name)
                new_file_path = os.path.join(root, new_file_name)

                # Rename the file
                os.rename(file_path, new_file_path)

                # Update references to the old name within the file
                with fileinput.FileInput(new_file_path, inplace=True, encoding='utf-8') as f:
                    for line in f:
                        sys.stdout.write(line.replace(old_name, new_name))

        print("Project files renamed and references updated successfully.")
    except Exception as e:
        print(f"An error occurred while renaming the project: {str(e)}")

if __name__ == "__main__":
    # Check the number of command-line arguments
    if len(sys.argv) != 3:
        print("Invalid number of arguments. Usage: python rename_project.py <old_name> <new_name>")
    else:
        # Extract command-line arguments
        old_name = sys.argv[1]
        new_name = sys.argv[2]

        rename_project(old_name, new_name)
