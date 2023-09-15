-- Keep a log of any SQL queries you execute as you solve the mystery.

.tables
.schema
SELECT * FROM crime_scene_reports WHERE month = '7' AND day = '28' AND street = 'Humphrey Street';

SELECT license_plate FROM bakery_security_logs WHERE id < 260 AND activity = 'entrance' AND license_plate NOT IN (SELECT license_plate FROM bakery_security_logs WHERE id < 260 AND activity = 'exit');

sqlite> SELECT * FROM interviews WHERE transcript LIKE '%bakery%';
SELECT account_number FROM atm_transactions WHERE month = '7' AND day = '28' AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw';

SELECT passport_number FROM people
WHERE license_plate IN(
     SELECT license_plate
     FROM bakery_security_logs
     WHERE year = '2021' AND month = '7' AND hour = '10' AND minute >' 15' AND minute <' 26'
     AND activity = 'exit' AND license_plate IN (
         SELECT license_plate FROM bakery_security_logs
         WHERE id < 261 AND activity = 'entrance'
         AND license_plate NOT IN (
             SELECT license_plate FROM bakery_security_logs WHERE id < 261 AND activity = 'exit')))
              AND id = (
                 SELECT person_id FROM bank_accounts
                 WHERE account_number IN (
                     SELECT account_number FROM atm_transactions
                     WHERE month = '7' AND day = '28'
                     AND atm_location = 'Leggett Street'
                     AND transaction_type = 'withdraw'));

SELECT * FROM phone_calls WHERE day ='28'AND duration <= 60;

SELECT * FROM phone_calls WHERE day ='28'AND duration <= 60 AND caller = (SELECT phone_number FROM people WHERE name = 'Bruce');

sqlite> SELECT * FROM people WHERE phone_number = (SELECT receiver FROM phone_calls WHERE day ='28'AND duration <= 60 AND caller = (SELECT phone_number FROM people WHERE name = 'Bruce'));

SELECT * FROM passengers WHERE passport_number = (
    SELECT passport_number FROM people
WHERE license_plate IN(
     SELECT license_plate
     FROM bakery_security_logs
     WHERE year = '2021' AND month = '7' AND hour = '10' AND minute >' 15' AND minute <' 26'
     AND activity = 'exit' AND license_plate IN (
         SELECT license_plate FROM bakery_security_logs
         WHERE id < 261 AND activity = 'entrance'
         AND license_plate NOT IN (
             SELECT license_plate FROM bakery_security_logs WHERE id < 261 AND activity = 'exit')))
              AND id = (
                 SELECT person_id FROM bank_accounts
                 WHERE account_number IN (
                     SELECT account_number FROM atm_transactions
                     WHERE month = '7' AND day = '28'
                     AND atm_location = 'Leggett Street'
                     AND transaction_type = 'withdraw')));

SELECT city FROM airports WHERE id = (SELECT destination_airport_id FROM flights WHERE id = '36');



