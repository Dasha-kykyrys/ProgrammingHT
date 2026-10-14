import re

def words():
    text = input().lower().replace("_"," ")
    words = re.findall(r'\w+(?:-\w+)*', text)
    nonrepeating_words = []
    for word in words:
        if word not in nonrepeating_words:
            nonrepeating_words.append(word)
    print("Разбиение на отдельные слова: ", words)
    print("Удаление повторов: ", nonrepeating_words)

words()
