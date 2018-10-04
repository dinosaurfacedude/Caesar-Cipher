choice = input("do you want to encrypt(-e) or decrypt?(-d)")
try:
	if choice == "-e":
		filetoopen = input("Please enter a file name. Include filetype.")
		file = open(filetoopen, "r")
		message = file.read()
		word = ""
		i = 0
		key = input("please enter a shifting key. Only 1-26 please. \n")
		if int(key) < 1:
			print("The key cannot be less than one.")
			exit()
		elif int(key) > 26:
			print("The key should not be more than 26.")
			exit()
		else:
			while i < len(message)-1:
				encrypt = ord(message[i])
				encrypted = encrypt + int(key)
				if encrypted > 126:
					encrypted = encrypted - 126 + 33
				letter = chr(encrypted)
				word = word + letter
				i = i + 1
			file1 = open("encrypted.txt", "w")
			writefile = file1.write(word)
			print("The message has been encrypted in encrypted.txt")
			file.close()
			file1.close()
			i = 0
	elif choice == "-d":
		filetoopen = input("please enter the file name. Include the filetype.")
		file = open(filetoopen, "r")
		message = file.read()
		word = ""
		i = 0
		num = input ("please enter a shifting key. Using the correct shifting key will unlock the message.")
		if int(num) < 1:
			print("The number cannot be less than one.")
			exit()
		elif int(num) > 26:
			print("the number cannot be more than 26.")
		else:
			while i < len(message)-1:
				decrypt = ord(message[i])
				decrypted = decrypt - int(num)
				if decrypted < 32:
					decrypted = decrypted + 126 - 33
				letter = chr(decrypted)
				word = word + letter
				i = i + 1
			file1 = open("decrypted-message.txt", "w")
			file1.write(word)
			print ("message decrypted. Results found in decrypted-message.txt")
			file.close()
			file1.close()
	else:
		print("only type -e or -d. No creativity allowed.")
except FileNotFoundError:
	print("I cannot find the file. Does it exist? Did you misspell it? Be sure to include the filetype (things like .txt or .doc)")
except ValueError:
	print("Only enter a number. You cannot shift using a letter.")
