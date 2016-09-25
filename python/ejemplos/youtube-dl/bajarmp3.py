#!/usr/bin/env python


from __future__ import unicode_literals
import youtube_dl
import sys

urls = sys.stdin.readlines()

class MyLogger(object):
    def debug(self, msg):
        pass

    def warning(self, msg):
        pass

    def error(self, msg):
        print(msg)

        
def my_hook(d):
    if d['status'] == 'finished':
        print('Done downloading, now converting ...')


ydl_opts = {
    'format': 'bestaudio/best',
    'postprocessors': [{
        'key': 'FFmpegExtractAudio',
        'preferredcodec': 'mp3',
        'preferredquality': '192',
    }],
    'logger': MyLogger(),
    'progress_hooks': [my_hook],
}
for u in urls:
    with youtube_dl.YoutubeDL(ydl_opts) as ydl:
        ydl.download(u)
