QGoogleAuth
===========

Qt implementation of Google Authenticator for mobile devices.

The intention of this project is to create a Qt implementation of the Google Authenticator: http://code.google.com/p/google-authenticator
The project is composed by a library that, given a secret key, calculates the current valid PIN using an HOTP and a TOTP mechanism (more informations available here: http://en.wikipedia.org/wiki/Time-based_One-time_Password_Algorithm ) and by a small test application.

References
==========
The base32_decode source code is taken by Google PAM module for Google Authenticator, while hmacSha1 has been taken by this code snippet http://qt-project.org/wiki/HMAC-SHA1. The external folder contains a very basic example of a working (I've tested it with the same key comparing generated PIN with the Android Google Authenticator one) Google Authenticator.