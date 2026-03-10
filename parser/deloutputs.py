import os
import re

def delete_files(file_prefix, file_extension):
    # Path to the current script
    script_directory = os.path.dirname(os.path.abspath(__file__))
    # Path to the 'outputs' folder (one level up, then into 'outputs')
    directory = os.path.join(script_directory, '..', 'outputs')
    directory = os.path.abspath(directory)
    
    # Check if the directory exists
    if not os.path.exists(directory):
        print(f"Directory {directory} not found.")
        return

    pattern = re.compile(rf'^{file_prefix}(\d*)\.{file_extension}$')
    files = []
    
    # Search for files in the directory
    for filename in os.listdir(directory):
        match = pattern.match(filename)
        if match:
            # If no number is present (e.g., link_map.csv), assume 0
            num = int(match.group(1)) if match.group(1) else 0
            files.append((num, filename))

    if not files:
        print(f"No {file_prefix} files found with extension .{file_extension}.")
        return
    
    # Find the highest number to limit the loop
    max_num = max(num for num, _ in files)
    
    # Sequential deletion 
    for num in range(max_num + 1):
        suffix = str(num) if num > 0 else ''
        filename = f'{file_prefix}{suffix}.{file_extension}'
        filepath = os.path.join(directory, filename)
        
        if os.path.exists(filepath):
            os.remove(filepath)
            print(f"Deleted {filename}")
        else:
            # In case a file in the sequence is missing
            print(f"File {filename} not found, stopping for {file_prefix}")

# 1. Delete link_map files (CSV)
delete_files('link_map', 'csv')

# 2. Delete routing-tables files (LOG)
delete_files('routing-tables', 'log')

# 3. Delete traffic_over_nodes files (CSV)
delete_files('traffic_over_nodes', 'csv')
