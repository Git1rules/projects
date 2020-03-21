#!/usr/bin/python
# Author	: Boris Alexandrov
# Date		: February 2, 2017
# Purpose	: the class parses the ini file for email application into series of lists 
#		: which will later be  accessed downstream
####################################################################################

class iniFileReader:
    def __init__ (self,filename):
        self.fileName=filename
        fp=open(self.fileName)
        self.lines=fp.read().splitlines()
        fp.close()
        self.recipients=self.lines[0].split(':')
        del self.recipients[0]

        self.ccrecipients=self.lines[1].split(':')
        del self.ccrecipients[0]

        line=self.lines[2].split(':')
        self.subject=line[1].rstrip()


        line=self.lines[3].split(':')

        if (line[1].rstrip() == 'FILE'):
                filename=line[2].rstrip()
                fp1=open(filename)
                self.body=fp1.read()
                fp1.close()
        else:
                self.body=line[1]

        line=self.lines[4].split(':')

        self.username=line[1].rstrip()


        line=self.lines[5].split(':')

        self.password=line[1].rstrip()


        line=self.lines[6].split(':')

        self.smtphost=line[1].rstrip()


        line=self.lines[7].split(':')

        self.port=line[1].rstrip()

        self.attachments=self.lines[8].split(':')
        del self.attachments[0]
