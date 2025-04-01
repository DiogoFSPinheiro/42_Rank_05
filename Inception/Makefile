all: build

data:
	mkdir -p /home/diogosan/data/mariadb && mkdir -p /home/diogosan/data/wordpress

build: data
	cd srcs && docker compose up --build
	
clean:
	cd srcs && docker system prune -a
	docker volume rm $$(docker volume ls -q)
	

