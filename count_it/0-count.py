#!/usr/bin/python3
"""
Count words in the titles of hot articles in a subreddit.
"""
import requests


def count_words(subreddit, word_list, after=None, counts=None):
    """
    Queries the Reddit API and counts occurrences of words in titles of posts.

    Args:
        subreddit (str): The subreddit to search.
        word_list (list): List of keywords to count.
        after (str): The 'after' parameter for pagination.
        counts (dict): Dictionary to store counts of keywords.
    """
    if counts is None:
        counts = {word.lower(): 0 for word in word_list}

    headers = {
        'User-Agent': 'Python3:holberton.task:v1.0 (by /u/your_username)'
    }

    url = (
        f"https://www.reddit.com/r/{subreddit}/hot.json"
    )

    params = {"after": after}

    response = requests.get(
        url,
        headers=headers,
        params=params,
        allow_redirects=False
    )

    if response.status_code != 200:
        return

    data = response.json().get("data", {})
    posts = data.get("children", [])

    for post in posts:
        title = post.get("data", {}).get("title", "").lower().split()
        for word in word_list:
            word_lower = word.lower()
            counts[word_lower] += title.count(word_lower)

    after = data.get("after")

    if after is not None:
        count_words(subreddit, word_list, after, counts)
    else:
        # Sort and print results
        sorted_counts = sorted(
            [(word, count) for word, count in counts.items() if count > 0],
            key=lambda x: (-x[1], x[0])
        )
        for word, count in sorted_counts:
            print(f"{word}: {count}")
