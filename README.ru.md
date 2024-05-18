# Apache Maven registry

![Github](https://img.shields.io/badge/-Github-0a0a0a?style=for-the-badge&logo=Github)
![Maven](https://img.shields.io/badge/-Maven-0a0a0a?style=for-the-badge&logo=ApacheMaven)

### [English version](https://github.com/Mark1708/github-maven-package-example/blob/main/README.md)

Вы можете настроить Apache Maven для публикации пакетов в GitHub Packages  и их использование в качестве зависимостей в проекте Java.

## Генерируем стандартный Maven проект

```bash
mvn archetype:generate -DgroupId=example.com -DartifactId=github-maven-package-example -DarchetypeArtifactId=maven-archetype-quickstart -DarchetypeVersion=1.4 -DinteractiveMode=false

mvn validate

mvn clean install
```

## Редактируем pom.xml

#### Изменяем properties

```xml
<properties>  
  <project.build.sourceEncoding>UTF-8</project.build.sourceEncoding>  
  <maven.compiler.source>11</maven.compiler.source>  
  <maven.compiler.target>11</maven.compiler.target>  
  <java.version>11</java.version>  
  
  <github.maven-plugin>0.12</github.maven-plugin>  
  <github.repository.owner>GITHUB_USERNAME</github.repository.owner>  
  <github.repository.name>GITHUB_REPO</github.repository.name>  
</properties>
```
> Заменяем <GITHUB_USERNAME> и <GITHUB_REPO> на реальные данные

#### Добавляем distributionManagement

```xml
<distributionManagement>  
  <repository>  
    <id>github</id>  
    <name>GitHub ${github.repository.owner} Apache Maven Packages</name>  
	<url>https://maven.pkg.github.com/${github.repository.owner}/${github.repository.name}</url>  
  </repository>  
</distributionManagement>
```


#### Изменяем build

```xml
<build>  
  <pluginManagement>  
    <plugins>  
      <plugin>  
        <groupId>org.apache.maven.plugins</groupId>  
        <artifactId>maven-plugin-plugin</artifactId>  
        <version>3.6.0</version>  
        <configuration>  
          <skipErrorNoDescriptorsFound>true</skipErrorNoDescriptorsFound>  
        </configuration>  
      </plugin>  
      <plugin>  
        <groupId>org.apache.maven.plugins</groupId>  
        <artifactId>maven-site-plugin</artifactId>  
        <version>3.9.1</version>  
      </plugin>  
    </plugins>  
  </pluginManagement>  
  <plugins>  
    <plugin>  
      <groupId>org.apache.maven.plugins</groupId>  
      <artifactId>maven-compiler-plugin</artifactId>  
      <version>3.8.1</version>  
      <configuration>  
        <source>${java.version}</source>  
        <target>${java.version}</target>  
      </configuration>  
    </plugin>  
  
    <plugin>  
      <groupId>org.apache.maven.plugins</groupId>  
      <artifactId>maven-release-plugin</artifactId>  
      <version>3.0.0-M1</version>  
    </plugin>  
  </plugins>  
</build>
```

## Добавляем простой класс User

```java
public class User {  
  
    private String username;  
    private String password;  
  
    public User(String username, String password) {  
        this.username = username;  
        this.password = password;  
    }  
    
    public User() {  
    }  
    
    public String getUsername() {  
        return username;  
    }  
    
    public void setUsername(String username) {  
        this.username = username;  
    }  
    
    public String getPassword() {  
        return password;  
    }  
    
    public void setPassword(String password) {  
        this.password = password;  
    }  
    
    @Override  
    public boolean equals(Object o) {  
        if (this == o) return true;  
        if (!(o instanceof User)) return false;  
        User user = (User) o;  
        return getUsername().equals(user.getUsername()) && getPassword().equals(user.getPassword());  
    }  
    
    @Override  
    public int hashCode() {  
        return Objects.hash(getUsername(), getPassword());  
    }  
    
    @Override  
    public String toString() {  
        return "User{" +  
                "username='" + username + '\'' +  
                ", password='" + password + '\'' +  
                '}';  
    }
}
```

## Убедимся, что не ошиблись и установим пакеты

```bash
mvn validate

mvn clean install
```

## Подготовка к деплою

Отредактируем файл  `~/.m2/settings.xml` чтобы доказать Github серьёзность своих намериний)

`vim ~/.m2/settings.xml`

```xml
<settings xmlns="http://maven.apache.org/SETTINGS/1.0.0"
  xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
  xsi:schemaLocation="http://maven.apache.org/SETTINGS/1.0.0
                      http://maven.apache.org/xsd/settings-1.0.0.xsd">

  <activeProfiles>
    <activeProfile>github</activeProfile>
  </activeProfiles>

  <profiles>
    <profile>
      <id>github</id>
      <repositories>
        <repository>
          <id>central</id>
          <url>https://repo1.maven.org/maven2</url>
        </repository>
        <repository>
          <id>github</id>
          <url>https://maven.pkg.github.com/<GITHUB_USERNAME>/<GITHUB_REPO></url>
          <snapshots>
            <enabled>true</enabled>
          </snapshots>
        </repository>
      </repositories>
    </profile>
  </profiles>

  <servers>
    <server>
      <id>github</id>
      <username><GITHUB_USERNAME></username>
      <password><GITHUB_ACCESS_TOKEN></password>
    </server>
  </servers>
</settings>
```

> Заменяем <GITHUB_USERNAME>,  <GITHUB_REPO> и <GITHUB_ACCESS_TOKEN> </br>
> Вам нужен токен доступа с правами: `publish, install, and delete private, internal, and public packages`

## Деплой

Тут всё просто:
```shell
mvn deploy
```

## Результат

В своём репозитории вы можете найти такую прелесть:
```xml
<dependency>  
  <groupId>example.com</groupId>  
  <artifactId>github-maven-package-example</artifactId>  
  <version>1.0-SNAPSHOT</version>  
</dependency>
```

Если репозиторий публичный, то зависимость доступна всем!

> Но если вы это делали в приватном, то на устройстве, где вы будете использовать эту зависимость потребуется настроить такой же `~/.m2/settings.xml` файл. 
 
### Удачи !)

## Другие ресурсы
-   [Boilerplates](https://github.com/Mark1708/boilerplates) - Шаблоны разных проектов
-   [Cheat-Sheets](https://github.com/Mark1708/cheat-sheets) - Справочник по различным инструментам и технологиям
-   [Habr](https://habr.com/ru/users/Mark1708/posts) - Здесь я иногда пишу о чем-то интересном

## Contact
Created by [Gurianov Mark](https://mark1708.github.io/) - feel free to contact me!
#### +7(962)024-50-04 | mark1708.work@gmail.com | [github](http://github.com/Mark1708)

![Readme Card](https://github-readme-stats.vercel.app/api/pin/?username=mark1708&repo=github-maven-package-example&theme=chartreuse-dark&show_icons=true)
