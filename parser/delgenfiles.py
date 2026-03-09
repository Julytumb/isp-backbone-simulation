import os
import re

def delete_files(file_type):
    script_directory = os.path.dirname(os.path.abspath(__file__))
    directory = os.path.join(script_directory, '..','generated_sources')
    directory = os.path.abspath(directory)
    pattern = re.compile(rf'^{file_type}(\d*)\.csv$')
    files = []
    
    for filename in os.listdir(directory):
        match = pattern.match(filename)
        if match:
            num = int(match.group(1)) if match.group(1) else 0
            files.append((num, filename))

    if not files:
        print(f"No {file_type} files found.")
        return
    
    max_num = max(num for num, _ in files)
    for num in range(max_num + 1):
        suffix = str(num) if num > 0 else ''
        filename = f'{file_type}{suffix}.csv'
        filepath = os.path.join(directory, filename)
        if os.path.exists(filepath):
            os.remove(filepath)
            print(f"Deleted {filename}")
        else:
            print(f"File {filename} not found, stopping for {file_type}")

# Delete links, routes, traffic files
delete_files('links')
delete_files('routes')
delete_files('traffic')