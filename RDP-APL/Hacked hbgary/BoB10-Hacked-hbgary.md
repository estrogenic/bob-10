---
title: BoB10-Hacked-hbgary
tags: []
---

# Hacked hbgary
작성자: BoB 10기 취약점분석 트랙 교육생 김지수  
작성일: 21-07-20

스토리: 2009년, 이강석 멘토님은 HBGary Responder Professional 이라는 리버싱 툴을 회사차원에서 구매했으나, 필요했던 런타임 분석 기능이 작동되지 않아 개발사에 수차례 환불 이메일을 보냈다.

하지만 어떤 이유로 환불받지 않았고, 나중에 HBGary 회사는 2011년에 어나니머스 조직에 의해 해킹되어 정보가 유출됐다.

그런데 정보가 유출되면서 멘토님과 나눈 이메일도 같이 유출되어 공개되었다.

> **이메일을 보낼 때 상대방 메일이 해킹돼 유출될 수 있음을 알아야 한다!**

<img src="/static/hbg2.png" width="30%"/>

## 기술적으로 무엇이 문제였나?

1. 런타임 분석 기능이 작동되지 않음
2. 널리 알려진 공격 기법에 대응하지 못하는 커스텀 소프트웨어 사용 

## 실무자가 원했던 기능은 뭐였는가

첫번째로, blackhat 2007 Active Reversing slide
presentation에서 언급된 Runtime Malware Analysis 기능이 잘 동작하는 것을 원했을 것이다.

두번째로 멘토님은 보안을 항상 신경쓰고, 패스워드 관리도 잘 해서 공격을 당하지 않을 것이라 생각했지만 엉뚱한 곳에서 정보가 유출됐다.

실무자는 hbg와 주고받은 이메일이 해킹되어 정보가 유출되지 않는 보안성을 겸비하는 것을 가정했고, 또한 원했을 것이다.

세번째로 몇번이나 문의를 넣었는데 테스트 환경을 요청하긴 커녕 아무 응답이 없었다. 실무자는 재대로된 customer service를 원했을 것이다.

## hbgary가 해킹을 당한 이유는?

hbg는 웹사이트 관리를 위해 SQL 인젝션 공격에 취약한 CMS(content management system)를 사용했고, 서버 DB의 PW가 유출당했다.

CMS는 GET 형식으로 파라미터를 받았으며 검사를 재대로 하지 못했다. 따라서 명령어는 그대로 백엔드의 SQL로 전송됐다.

어나니머스는 암호에 대한 MD5 해쉬를 여러 개 추출할 수 있었다. 불행히도, 암호는 매우 간단했다. 그들은 레인보우 테이블을 사용해 MD5 해쉬로부터 PW를 추출해 냈다.

Root 패스워드를 얻기 위해서 실행되고 있는 소프트웨어의 취약점을 찾아냈으며 회사 내부 특정 기기의 권한을 획득했다.(이메일 서버)

이후 회사 이메일 계정에 접근할 수 있었으며 hbg CEO의 이메일을 통해 사회 공학적 공격으로 웹 서버, 백업 서버 등 다른 기기의 패스워드를 알아냈다.

또한 구글 앱에 저장된 회사 연구 문서와 수만개의 메일에 접근할 수 있었다.

~~그리고 다 털렸다.~~

## hbgary의 문제점

* 회사 메일 서버에 대한 보안 관리가 이루어지지 않음(업데이트, 주기적인 삭제, 따로 분리 등)

* 오래된 소프트웨어 시스템과 외부 클라우드 시스템을 사용

* 보안에 취약한 암호를 사용

* 구글 앱의 다단계 인증을 사용하지 않음

<img src="/static/hbg1.png" width="30%"/>
* hbg의 CEO의 트위터 계정도 해킹당해 그의 개인정보 또한 유출되었으며 이러한 부분 또한 동일한 패스워드를 사용했기 때문으로 추측된다.

## Reference
* [
The HBGary Federal Hack](https://dougvitale.wordpress.com/2012/01/13/the-hbgary-federal-hack/)

* [TOP 10 IN 2011: AN 'EXPLOSIVE' YEAR IN SECURITY](https://cert.ir/news/entry/11975?language_id=1)

* [What was the HBGary hack?](https://www.youtube.com/watch?v=VaJSSVQUfaw)
