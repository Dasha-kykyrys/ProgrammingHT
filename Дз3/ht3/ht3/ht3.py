import numpy as np
import re

def words():
    text = input().lower().replace("_"," ")
    words = re.findall(r'\w+(?:-\w+)*', text)
    nonrepeating_words = []
    for word in words:
        if word not in nonrepeating_words:
            nonrepeating_words.append(word)
    array_words = np.array(nonrepeating_words)
    print("Разбиение на отдельные слова: ", words)
    print("Удаление повторов: ", array_words)
    words.clear()
    nonrepeating_words.clear()

words()
