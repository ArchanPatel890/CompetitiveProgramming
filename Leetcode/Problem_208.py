from collections import defaultdict

class TrieNode:
    def __init__(self):
        self.char_dict = defaultdict(TrieNode)

class Trie:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = TrieNode()
        self.stop = '$'

    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        if not word:
            return
        curr = self.root
        for c in word:
            if c not in curr.char_dict:
                curr.char_dict[c] = TrieNode()
            curr = curr.char_dict[c]
        curr.char_dict[self.stop] = None

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        if not word:
            return
        curr = self.root
        for c in word:
            if c not in curr.char_dict:
                return False
            curr = curr.char_dict[c]
        return self.stop in curr.char_dict

    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        if not prefix:
            return
        curr = self.root
        for c in prefix:
            if c not in curr.char_dict:
                return False
            curr = curr.char_dict[c]
        return True