#!/usr/bin/node

const request = require('request');

function fetchCharacter (url) {
  return new Promise((resolve, reject) => {
    request(url, (error, response, body) => {
      if (error) {
        return reject(error);
      }
      if (response.statusCode !== 200) {
        return reject(new Error(`Error: ${response.statusCode}`)); // Correction ici
      }
      resolve(JSON.parse(body).name);
    });
  });
}

async function getCharacterNames (movieId) {
  const url = `https://swapi-api.hbtn.io/api/films/${movieId}/`;

  request(url, async (error, response, body) => {
    if (error) {
      console.error(error);
      return;
    }

    if (response.statusCode !== 200) {
      console.error(`Error: ${response.statusCode}`);
      return;
    }

    try {
      const filmData = JSON.parse(body);
      const characterUrls = filmData.characters;

      for (const characterUrl of characterUrls) {
        const name = await fetchCharacter(characterUrl);
        console.log(name);
      }
    } catch (err) {
      console.error('Error parsing JSON or fetching characters:', err);
    }
  });
}

const movieId = process.argv[2];
if (!movieId) {
  console.error('Usage: ./0-starwars_characters.js <Movie ID>');
  process.exit(1);
}

getCharacterNames(movieId);
