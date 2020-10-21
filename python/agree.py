answer = input("Do you agree? ")

if answer == "y" or answer == "Y":
    print("Agreed.")
elif answer == "n" or answer == "N":
    print("Not agreed.")

secondAnswer = input("Do you agree? ")

if secondAnswer.lower() in ["y", "yes"]:
    print("Agreed.")
elif secondAnswer.lower() in ["n", "no"]:
    print("Not agreed.")