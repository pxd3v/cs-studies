words = set()

def check(word, words):
    if word.lower() in words:
        return True
    else:
        return False

def loadWords(dictionary, words):
    file = open(dictionary, "r")
    for line in file:
        words.add(line.rstrip())
    file.close()
    return True

def size(words):
    return len(words)

def unload():
    return True

loadWords("words.txt", words)

hasBanana = check("banana", words)

wordsSize = size(words);
for word in words:
    print(word)

print(hasBanana)

print(wordsSize)