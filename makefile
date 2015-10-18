#all:main.x main1.x

main.x:test.c
	gcc test.c -o main.x
main1.x:test1.c
	gcc test1.c -o main1.x
