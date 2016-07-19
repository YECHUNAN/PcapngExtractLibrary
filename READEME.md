# pcapngToCsv notes

Problem 1: Still struggling with efficient methods of reading optional data without moving back and forth in the file.

____________

Problem 2: Why do I get different timestamp from the same pcapng file each time?

Problem 2 solution: Have fixed a ifstream bug. When placed as the first member variable of the pcapngToCsv class, its input(read) operation will corrupt the other member variables of the class. Define it as the last member solves this problem.

Problem 3: How to deal with the difference in endianess?

Problem 3 solution: by checking the order of the magic byte. We can tell whether the machine is big endian or small endian.
